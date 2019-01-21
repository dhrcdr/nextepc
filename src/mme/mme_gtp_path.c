#define TRACE_MODULE _mme_gtp_path
#include "core_debug.h"
#include "core_pkbuf.h"

#include "gtp/gtp_node.h"
#include "gtp/gtp_path.h"
#include "gtp/gtp_xact.h"

#include "mme_event.h"
#include "mme_gtp_path.h"
#include "mme_s11_build.h"
#include "mme_sm.h"

static int _gtpv2_c_recv_cb(sock_id sock, void *data)
{
    char buf[CORE_ADDRSTRLEN];
    status_t rv;
    event_t e;
    pkbuf_t *pkbuf = NULL;
    c_sockaddr_t from;
    gtp_header_t *gtp_h = NULL;

    d_assert(sock, return -1, "Null param");

    rv = gtp_recvfrom(sock, &pkbuf, &from);
    if (rv != CORE_OK)
    {
        if (errno == EAGAIN)
            return 0;

        return -1;
    }

    d_trace(50, "[GTPv2] RECV : ");
    d_trace_hex(50, pkbuf->payload, pkbuf->len);

    gtp_h = (gtp_header_t *)pkbuf->payload;
    if (gtp_h->type == GTP_ECHO_REQUEST_TYPE)
    {
        pkbuf_t *echo_rsp;

        d_trace(3, "[GTPv2] RECV Echo Request from [%s]\n",
                CORE_ADDR(&from, buf));
        echo_rsp = gtp_handle_echo_req(pkbuf);
        if (echo_rsp)
        {
            ssize_t sent;

            /* Echo reply */
            d_trace(3, "[GTPv2] SEND Echo Response to [%s]\n",
                    CORE_ADDR(&from, buf));

            sent = core_sendto(sock,
                    echo_rsp->payload, echo_rsp->len, 0, &from);
            if (sent < 0 || sent != echo_rsp->len)
            {
                d_error("core_sendto failed(%d:%s)", errno, strerror(errno));
            }
            pkbuf_free(echo_rsp);
        }

        pkbuf_free(pkbuf);
    }
    else if (gtp_h->type == GTP_MBMS_SESSION_START_REQUEST_TYPE)
    {
        pkbuf_t *pkb_resp;
        gtp_header_t *gtph_resp;
        c_uint16_t length;

        d_trace(3, "[GTPv2] RECV MBMS Session Start Request from [%s]\n",
                CORE_ADDR(&from, buf));

        /* TODO: Send MBMS Session Start Request over M3AP */
        /* END TODO */

        pkb_resp = pkbuf_alloc(0, MAX_SDU_LEN);
        d_assert(pkb_resp, return -1, "Can't allocate pkbuf");
        gtph_resp = (gtp_header_t *)pkb_resp->payload;

        /* CREATE HEADER */
        gtph_resp->flags = (2 << 5); /* set version */
        gtph_resp->flags |= (1 << 3); /* set TEID flag */
        gtph_resp->type = GTP_MBMS_SESSION_START_RESPONSE_TYPE;
        length = 27;     /* length of TEID (4) length of Sequence Number (3) + Spare (1) + Cause IE (6) + F-TEID IE (13) */
        gtph_resp->length = htons(length);

        /* COPY TEID */
        *((c_uint8_t *)pkb_resp->payload + 4) = *((c_uint8_t *)pkbuf->payload + 17);
        *((c_uint8_t *)pkb_resp->payload + 5) = *((c_uint8_t *)pkbuf->payload + 18);
        *((c_uint8_t *)pkb_resp->payload + 6) = *((c_uint8_t *)pkbuf->payload + 19);
        *((c_uint8_t *)pkb_resp->payload + 7) = *((c_uint8_t *)pkbuf->payload + 20);

        /* COPY SEQUENCE NUMBER */
        *((c_uint8_t *)pkb_resp->payload + 8) = *((c_uint8_t *)pkbuf->payload + 8);
        *((c_uint8_t *)pkb_resp->payload + 9) = *((c_uint8_t *)pkbuf->payload + 9);
        *((c_uint8_t *)pkb_resp->payload + 10) = *((c_uint8_t *)pkbuf->payload + 10);

        /* CREATE CAUSE IE */
        *((c_uint8_t *)pkb_resp->payload + 12) = 2;  /* Type */
        *((c_uint8_t *)pkb_resp->payload + 13) = 0;  /* Length */
        *((c_uint8_t *)pkb_resp->payload + 14) = 2;
        *((c_uint8_t *)pkb_resp->payload + 15) = 0;  /* Spare | Instance */
        *((c_uint8_t *)pkb_resp->payload + 16) = 16; /* Cause value */
        *((c_uint8_t *)pkb_resp->payload + 17) = 0;  /* Spare | PCE | BCE | CS */

        /* COPY F-TEID IE */
        *((c_uint8_t *)pkb_resp->payload + 18) = *((c_uint8_t *)pkbuf->payload + 12);
        *((c_uint8_t *)pkb_resp->payload + 19) = *((c_uint8_t *)pkbuf->payload + 13);
        *((c_uint8_t *)pkb_resp->payload + 20) = *((c_uint8_t *)pkbuf->payload + 14);
        *((c_uint8_t *)pkb_resp->payload + 21) = *((c_uint8_t *)pkbuf->payload + 15);
        *((c_uint8_t *)pkb_resp->payload + 22) = *((c_uint8_t *)pkbuf->payload + 16);
        *((c_uint8_t *)pkb_resp->payload + 23) = *((c_uint8_t *)pkbuf->payload + 17);
        *((c_uint8_t *)pkb_resp->payload + 24) = *((c_uint8_t *)pkbuf->payload + 18);
        *((c_uint8_t *)pkb_resp->payload + 25) = *((c_uint8_t *)pkbuf->payload + 19);
        *((c_uint8_t *)pkb_resp->payload + 26) = *((c_uint8_t *)pkbuf->payload + 20);
        *((c_uint8_t *)pkb_resp->payload + 27) = *((c_uint8_t *)pkbuf->payload + 21);
        *((c_uint8_t *)pkb_resp->payload + 28) = *((c_uint8_t *)pkbuf->payload + 22);
        *((c_uint8_t *)pkb_resp->payload + 29) = *((c_uint8_t *)pkbuf->payload + 23);
        *((c_uint8_t *)pkb_resp->payload + 30) = *((c_uint8_t *)pkbuf->payload + 24);

        pkb_resp->len = 31;

        if (pkb_resp)
        {
            ssize_t sent;

            /* Echo reply */
            d_trace(3, "[GTPv2] SEND MBMS Session Start Response to [%s]\n",
                    CORE_ADDR(&from, buf));

            sent = core_sendto(sock,
                    pkb_resp->payload, pkb_resp->len, 0, &from);
            if (sent < 0 || sent != pkb_resp->len)
            {
                d_error("core_sendto failed(%d:%s)", errno, strerror(errno));
            }
            pkbuf_free(pkb_resp);
        }

        pkbuf_free(pkbuf);
    }
    else if (gtp_h->type == GTP_MBMS_SESSION_STOP_REQUEST_TYPE)
    {
        pkbuf_t *pkb_resp;
        gtp_header_t *gtph_resp;
        c_uint16_t length;

        d_trace(3, "[GTPv2] RECV MBMS Session Stop Request from [%s]\n",
                CORE_ADDR(&from, buf));

        /* TODO: Send MBMS Session Stop Request over M3AP */
        /* END TODO */

        pkb_resp = pkbuf_alloc(0, MAX_SDU_LEN);
        d_assert(pkb_resp, return -1, "Can't allocate pkbuf");
        gtph_resp = (gtp_header_t *)pkb_resp->payload;

        /* CREATE HEADER */
        gtph_resp->flags = (2 << 5); /* set version */
        gtph_resp->flags |= (1 << 3); /* set TEID flag */
        gtph_resp->type = GTP_MBMS_SESSION_STOP_RESPONSE_TYPE;
        length = 14;     /* length of TEID (4) length of Sequence Number (3) + Spare (1) + Cause IE (6) */
        gtph_resp->length = htons(length);

        /* COPY TEID */
        *((c_uint8_t *)pkb_resp->payload + 4) = *((c_uint8_t *)pkbuf->payload + 4);
        *((c_uint8_t *)pkb_resp->payload + 5) = *((c_uint8_t *)pkbuf->payload + 5);
        *((c_uint8_t *)pkb_resp->payload + 6) = *((c_uint8_t *)pkbuf->payload + 6);
        *((c_uint8_t *)pkb_resp->payload + 7) = *((c_uint8_t *)pkbuf->payload + 7);

        /* COPY SEQUENCE NUMBER */
        *((c_uint8_t *)pkb_resp->payload + 8) = *((c_uint8_t *)pkbuf->payload + 8);
        *((c_uint8_t *)pkb_resp->payload + 9) = *((c_uint8_t *)pkbuf->payload + 9);
        *((c_uint8_t *)pkb_resp->payload + 10) = *((c_uint8_t *)pkbuf->payload + 10);

        /* CREATE CAUSE IE */
        *((c_uint8_t *)pkb_resp->payload + 12) = 2;  /* Type */
        *((c_uint8_t *)pkb_resp->payload + 13) = 0;  /* Length */
        *((c_uint8_t *)pkb_resp->payload + 14) = 2;
        *((c_uint8_t *)pkb_resp->payload + 15) = 0;  /* Spare | Instance */
        *((c_uint8_t *)pkb_resp->payload + 16) = 16; /* Cause value */
        *((c_uint8_t *)pkb_resp->payload + 17) = 0;  /* Spare | PCE | BCE | CS */

        pkb_resp->len = 18;

        if (pkb_resp)
        {
            ssize_t sent;

            /* Echo reply */
            d_trace(3, "[GTPv2] SEND MBMS Session Stop Response to [%s]\n",
                    CORE_ADDR(&from, buf));

            sent = core_sendto(sock,
                    pkb_resp->payload, pkb_resp->len, 0, &from);
            if (sent < 0 || sent != pkb_resp->len)
            {
                d_error("core_sendto failed(%d:%s)", errno, strerror(errno));
            }
            pkbuf_free(pkb_resp);
        }

        pkbuf_free(pkbuf);
    }
    else
    {
        event_set(&e, MME_EVT_S11_MESSAGE);
        event_set_param1(&e, (c_uintptr_t)pkbuf);
        rv = mme_event_send(&e);
        if (rv != CORE_OK)
        {
            d_error("mme_event_send error");
            pkbuf_free(pkbuf);
            return -1;
        }
    }

    return 0;
}

static c_sockaddr_t *pgw_addr_find_by_family(list_t *list, int family)
{
    mme_pgw_t *pgw = NULL;
    d_assert(list, return NULL,);

    for (pgw = list_first(list); pgw; pgw = list_next(pgw))
    {
        d_assert(pgw->gnode, return NULL,);
        c_sockaddr_t *addr = pgw->gnode->sa_list;
        while(addr)
        {
            if (addr->c_sa_family == family)
            {
                return addr;
            }
            addr = addr->next;
        }
    }

    return NULL;
}

status_t mme_gtp_open()
{
    status_t rv;
    mme_sgw_t *sgw = NULL;

    rv = gtp_server_list(&mme_self()->gtpc_list, _gtpv2_c_recv_cb);
    d_assert(rv == CORE_OK, return CORE_ERROR,);
    rv = gtp_server_list(&mme_self()->gtpc_list6, _gtpv2_c_recv_cb);
    d_assert(rv == CORE_OK, return CORE_ERROR,);

    mme_self()->gtpc_sock = gtp_local_sock_first(&mme_self()->gtpc_list);
    mme_self()->gtpc_sock6 = gtp_local_sock_first(&mme_self()->gtpc_list6);
    mme_self()->gtpc_addr = gtp_local_addr_first(&mme_self()->gtpc_list);
    mme_self()->gtpc_addr6 = gtp_local_addr_first(&mme_self()->gtpc_list6);

    d_assert(mme_self()->gtpc_addr || mme_self()->gtpc_addr6,
            return CORE_ERROR, "No GTP Server");

    mme_self()->pgw_addr = pgw_addr_find_by_family(
            &mme_self()->pgw_list, AF_INET);
    mme_self()->pgw_addr6 = pgw_addr_find_by_family(
            &mme_self()->pgw_list, AF_INET6);
    d_assert(mme_self()->pgw_addr || mme_self()->pgw_addr6,
            return CORE_ERROR,);

    for (sgw = list_first(&mme_self()->sgw_list); sgw; sgw = list_next(sgw))
    {
        rv = gtp_client(sgw->gnode);
        d_assert(rv == CORE_OK, return CORE_ERROR,);
    }

    return CORE_OK;
}

status_t mme_gtp_close()
{
    sock_delete_list(&mme_self()->gtpc_list);
    sock_delete_list(&mme_self()->gtpc_list6);

    return CORE_OK;
}

status_t mme_gtp_send_create_session_request(mme_sess_t *sess)
{
    status_t rv;
    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;
    gtp_xact_t *xact = NULL;
    mme_ue_t *mme_ue = NULL;

    mme_ue = sess->mme_ue;
    d_assert(mme_ue, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_CREATE_SESSION_REQUEST_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_create_session_request(&pkbuf, h.type, sess);
    d_assert(rv == CORE_OK, return CORE_ERROR,
            "S11 build error");

    xact = gtp_xact_local_create(mme_ue->gnode, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}


status_t mme_gtp_send_modify_bearer_request(
        mme_bearer_t *bearer, int uli_presence)
{
    status_t rv;

    gtp_xact_t *xact = NULL;
    mme_ue_t *mme_ue = NULL;

    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;

    d_assert(bearer, return CORE_ERROR, "Null param");
    mme_ue = bearer->mme_ue;
    d_assert(mme_ue, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_MODIFY_BEARER_REQUEST_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_modify_bearer_request(
            &pkbuf, h.type, bearer, uli_presence);
    d_assert(rv == CORE_OK, return CORE_ERROR, "S11 build error");

    xact = gtp_xact_local_create(mme_ue->gnode, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

status_t mme_gtp_send_delete_session_request(mme_sess_t *sess)
{
    status_t rv;
    pkbuf_t *s11buf = NULL;
    gtp_header_t h;
    gtp_xact_t *xact = NULL;
    mme_ue_t *mme_ue = NULL;

    d_assert(sess, return CORE_ERROR, "Null param");
    mme_ue = sess->mme_ue;
    d_assert(mme_ue, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_DELETE_SESSION_REQUEST_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_delete_session_request(&s11buf, h.type, sess);
    d_assert(rv == CORE_OK, return CORE_ERROR, "S11 build error");

    xact = gtp_xact_local_create(mme_ue->gnode, &h, s11buf);
    d_assert(xact, return CORE_ERROR, "Null param");

    GTP_XACT_STORE_SESSION(xact, sess);

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

status_t mme_gtp_send_delete_all_sessions(mme_ue_t *mme_ue)
{
    status_t rv;
    mme_sess_t *sess = NULL, *next_sess = NULL;

    d_assert(mme_ue, return CORE_ERROR, "Null param");
    sess = mme_sess_first(mme_ue);
    while (sess != NULL)
    {
        next_sess = mme_sess_next(sess);

        if (MME_HAVE_SGW_S1U_PATH(sess))
        {
            mme_bearer_t *bearer = mme_default_bearer_in_sess(sess);
            d_assert(bearer,, "Null param");

            if (bearer && FSM_CHECK(&bearer->sm, esm_state_pdn_will_disconnect))
            {
                d_warn("PDN will disconnect[EBI:%d]", bearer->ebi);
            }
            else
            {
                rv = mme_gtp_send_delete_session_request(sess);
                d_assert(rv == CORE_OK, return CORE_ERROR,
                        "mme_gtp_send_delete_session_request error");
            }
        }
        else
        {
            mme_sess_remove(sess);
        }

        sess = next_sess;
    }

    return CORE_OK;
}

status_t mme_gtp_send_create_bearer_response(mme_bearer_t *bearer)
{
    status_t rv;

    gtp_xact_t *xact = NULL;
    mme_ue_t *mme_ue = NULL;

    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;

    d_assert(bearer, return CORE_ERROR, "Null param");
    mme_ue = bearer->mme_ue;
    d_assert(mme_ue, return CORE_ERROR, "Null param");
    xact = bearer->xact;
    d_assert(xact, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_CREATE_BEARER_RESPONSE_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_create_bearer_response(&pkbuf, h.type, bearer);
    d_assert(rv == CORE_OK, return CORE_ERROR, "S11 build error");

    rv = gtp_xact_update_tx(xact, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

status_t mme_gtp_send_update_bearer_response(mme_bearer_t *bearer)
{
    status_t rv;

    gtp_xact_t *xact = NULL;
    mme_ue_t *mme_ue = NULL;

    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;

    d_assert(bearer, return CORE_ERROR, "Null param");
    mme_ue = bearer->mme_ue;
    d_assert(mme_ue, return CORE_ERROR, "Null param");
    xact = bearer->xact;
    d_assert(xact, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_UPDATE_BEARER_RESPONSE_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_update_bearer_response(&pkbuf, h.type, bearer);
    d_assert(rv == CORE_OK, return CORE_ERROR, "S11 build error");

    rv = gtp_xact_update_tx(xact, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

status_t mme_gtp_send_delete_bearer_response(mme_bearer_t *bearer)
{
    status_t rv;

    gtp_xact_t *xact = NULL;
    mme_ue_t *mme_ue = NULL;

    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;

    d_assert(bearer, return CORE_ERROR, "Null param");
    mme_ue = bearer->mme_ue;
    d_assert(mme_ue, return CORE_ERROR, "Null param");
    xact = bearer->xact;
    d_assert(xact, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_DELETE_BEARER_RESPONSE_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_delete_bearer_response(&pkbuf, h.type, bearer);
    d_assert(rv == CORE_OK, return CORE_ERROR, "S11 build error");

    rv = gtp_xact_update_tx(xact, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

status_t mme_gtp_send_release_access_bearers_request(mme_ue_t *mme_ue)
{
    status_t rv;
    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;
    gtp_xact_t *xact = NULL;

    d_assert(mme_ue, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_RELEASE_ACCESS_BEARERS_REQUEST_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_release_access_bearers_request(&pkbuf, h.type);
    d_assert(rv == CORE_OK, return CORE_ERROR, "S11 build error");

    xact = gtp_xact_local_create(mme_ue->gnode, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

status_t mme_gtp_send_create_indirect_data_forwarding_tunnel_request(
        mme_ue_t *mme_ue)
{
    status_t rv;
    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;
    gtp_xact_t *xact = NULL;

    d_assert(mme_ue, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_CREATE_INDIRECT_DATA_FORWARDING_TUNNEL_REQUEST_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    rv = mme_s11_build_create_indirect_data_forwarding_tunnel_request(
            &pkbuf, h.type, mme_ue);
    d_assert(rv == CORE_OK, return CORE_ERROR, "S11 build error");

    xact = gtp_xact_local_create(mme_ue->gnode, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

status_t mme_gtp_send_delete_indirect_data_forwarding_tunnel_request(
        mme_ue_t *mme_ue)
{
    status_t rv;
    gtp_header_t h;
    pkbuf_t *pkbuf = NULL;
    gtp_xact_t *xact = NULL;

    d_assert(mme_ue, return CORE_ERROR, "Null param");

    memset(&h, 0, sizeof(gtp_header_t));
    h.type = GTP_DELETE_INDIRECT_DATA_FORWARDING_TUNNEL_REQUEST_TYPE;
    h.teid = mme_ue->sgw_s11_teid;

    pkbuf = pkbuf_alloc(TLV_MAX_HEADROOM, 0);
    d_assert(pkbuf, return CORE_ERROR, "S11 build error");

    xact = gtp_xact_local_create(mme_ue->gnode, &h, pkbuf);
    d_assert(xact, return CORE_ERROR, "Null param");

    rv = gtp_xact_commit(xact);
    d_assert(rv == CORE_OK, return CORE_ERROR, "xact_commit error");

    return CORE_OK;
}

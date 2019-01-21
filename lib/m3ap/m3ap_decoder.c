#define TRACE_MODULE _m3ap_decoder

#include "m3ap_message.h"

status_t m3ap_decode_pdu(m3ap_message_t *message, pkbuf_t *pkbuf)
{
    asn_dec_rval_t dec_ret = {0};

    d_assert(message, return CORE_ERROR,);
    d_assert(pkbuf, return CORE_ERROR,);
    d_assert(pkbuf->payload, return CORE_ERROR,);

    memset((void *)message, 0, sizeof(m3ap_message_t));
    dec_ret = m3_aper_decode(NULL, &asn_DEF_M3AP_M3AP_PDU, (void **)&message, 
            pkbuf->payload, pkbuf->len, 0, 0);

    if (dec_ret.code != RC_OK) 
    {
        d_error("Failed to decode M3AP-PDU[%d]", dec_ret.code);
        return CORE_ERROR;
    }

    //if (g_trace_mask && TRACE_MODULE >= 25)
        asn_fprint(stdout, &asn_DEF_M3AP_M3AP_PDU, message);

    return CORE_OK;
}

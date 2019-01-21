#ifndef _M3AP_MESSAGE_H__
#define _M3AP_MESSAGE_H__

#include "core_pkbuf.h"
#include "m3ap_asn1c.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Octets */
#define M3AP_CLEAR_DATA(__dATA) \
    do { \
        d_assert((__dATA), , "Null param"); \
        if ((__dATA)->buf) \
        { \
            CORE_FREE((__dATA)->buf); \
            (__dATA)->buf = NULL; \
            (__dATA)->size = 0; \
        } \
    } while(0)
#define M3AP_STORE_DATA(__dST, __sRC) \
    do { \
        d_assert((__sRC),, "Null param") \
        d_assert((__sRC)->buf,, "Null param") \
        d_assert((__dST),, "Null param") \
        M3AP_CLEAR_DATA(__dST); \
        (__dST)->size = (__sRC)->size; \
        (__dST)->buf = core_calloc((__dST)->size, sizeof(c_uint8_t)); \
        memcpy((__dST)->buf, (__sRC)->buf, (__dST)->size); \
    } while(0)

typedef struct M3AP_M3AP_PDU m3ap_message_t;

CORE_DECLARE(int) m3ap_decode_pdu(m3ap_message_t *message, pkbuf_t *pkbuf);
CORE_DECLARE(int) m3ap_encode_pdu(pkbuf_t **pkbuf, m3ap_message_t *message);
CORE_DECLARE(int) m3ap_free_pdu(m3ap_message_t *message);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif


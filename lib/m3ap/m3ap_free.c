#define TRACE_MODULE _m3ap_free

#include "m3ap_message.h"

status_t m3ap_free_pdu(m3ap_message_t *message)
{
    d_assert(message, return CORE_ERROR,);

    ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_M3AP_M3AP_PDU, message);

    return CORE_OK;
}

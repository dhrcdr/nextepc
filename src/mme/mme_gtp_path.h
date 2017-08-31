#ifndef __MME_S11_PATH_H__
#define __MME_S11_PATH_H__

#include "core_pkbuf.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CORE_DECLARE(status_t) mme_gtp_open();
CORE_DECLARE(status_t) mme_gtp_close();

CORE_DECLARE(status_t) mme_s11_send_to_sgw(
        mme_sess_t *sess, c_uint8_t type, pkbuf_t *pkbuf);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __MME_S11_PATH_H__ */
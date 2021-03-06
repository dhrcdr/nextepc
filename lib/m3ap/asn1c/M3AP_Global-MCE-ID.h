/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-IEs"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#ifndef	_M3AP_Global_MCE_ID_H_
#define	_M3AP_Global_MCE_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include "M3AP_PLMN-Identity.h"
#include "M3AP_MCE-ID.h"
#include "M3AP_ExtendedMCE-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct M3AP_ProtocolExtensionContainer;

/* M3AP_Global-MCE-ID */
typedef struct M3AP_Global_MCE_ID {
	M3AP_PLMN_Identity_t	 pLMN_Identity;
	M3AP_MCE_ID_t	 mCE_ID;
	M3AP_ExtendedMCE_ID_t	*extendedMCE_ID;	/* OPTIONAL */
	struct M3AP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_Global_MCE_ID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_M3AP_Global_MCE_ID;

#ifdef __cplusplus
}
#endif

#endif	/* _M3AP_Global_MCE_ID_H_ */
#include <asn_internal.h>

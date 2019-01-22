/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-IEs"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#ifndef	_M3AP_TMGI_H_
#define	_M3AP_TMGI_H_


#include <asn_application.h>

/* Including external dependencies */
#include "M3AP_PLMN-Identity.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct M3AP_ProtocolExtensionContainer;

/* M3AP_TMGI */
typedef struct M3AP_TMGI {
	M3AP_PLMN_Identity_t	 pLMNidentity;
	OCTET_STRING_t	 serviceID;
	struct M3AP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_TMGI_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_M3AP_TMGI;

#ifdef __cplusplus
}
#endif

#endif	/* _M3AP_TMGI_H_ */
#include <asn_internal.h>
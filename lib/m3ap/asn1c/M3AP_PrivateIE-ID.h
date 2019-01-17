/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-CommonDataTypes"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#ifndef	_M3AP_PrivateIE_ID_H_
#define	_M3AP_PrivateIE_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <OBJECT_IDENTIFIER.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum M3AP_PrivateIE_ID_PR {
	M3AP_PrivateIE_ID_PR_NOTHING,	/* No components present */
	M3AP_PrivateIE_ID_PR_local,
	M3AP_PrivateIE_ID_PR_global
} M3AP_PrivateIE_ID_PR;

/* M3AP_PrivateIE-ID */
typedef struct M3AP_PrivateIE_ID {
	M3AP_PrivateIE_ID_PR present;
	union M3AP_PrivateIE_ID_u {
		long	 local;
		OBJECT_IDENTIFIER_t	 global;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_PrivateIE_ID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_M3AP_PrivateIE_ID;
extern asn_CHOICE_specifics_t asn_SPC_M3AP_PrivateIE_ID_specs_1;
extern asn_TYPE_member_t asn_MBR_M3AP_PrivateIE_ID_1[2];
extern asn_per_constraints_t asn_PER_type_M3AP_PrivateIE_ID_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _M3AP_PrivateIE_ID_H_ */
#include <asn_internal.h>

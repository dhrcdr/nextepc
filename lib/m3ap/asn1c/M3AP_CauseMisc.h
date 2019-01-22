/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-IEs"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#ifndef	_M3AP_CauseMisc_H_
#define	_M3AP_CauseMisc_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum M3AP_CauseMisc {
	M3AP_CauseMisc_control_processing_overload	= 0,
	M3AP_CauseMisc_not_enough_user_plane_processing_resources	= 1,
	M3AP_CauseMisc_hardware_failure	= 2,
	M3AP_CauseMisc_om_intervention	= 3,
	M3AP_CauseMisc_unspecified	= 4
	/*
	 * Enumeration is extensible
	 */
} e_M3AP_CauseMisc;

/* M3AP_CauseMisc */
typedef long	 M3AP_CauseMisc_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_M3AP_CauseMisc_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_CauseMisc;
extern const asn_INTEGER_specifics_t asn_SPC_CauseMisc_specs_1;
asn_struct_free_f CauseMisc_free;
asn_struct_print_f CauseMisc_print;
asn_constr_check_f CauseMisc_constraint;
ber_type_decoder_f CauseMisc_decode_ber;
der_type_encoder_f CauseMisc_encode_der;
xer_type_decoder_f CauseMisc_decode_xer;
xer_type_encoder_f CauseMisc_encode_xer;
oer_type_decoder_f CauseMisc_decode_oer;
oer_type_encoder_f CauseMisc_encode_oer;
per_type_decoder_f CauseMisc_decode_uper;
per_type_encoder_f CauseMisc_encode_uper;
per_type_decoder_f CauseMisc_decode_aper;
per_type_encoder_f CauseMisc_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _M3AP_CauseMisc_H_ */
#include <asn_internal.h>
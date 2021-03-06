/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-CommonDataTypes"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#ifndef	_M3AP_Criticality_H_
#define	_M3AP_Criticality_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum M3AP_Criticality {
	M3AP_Criticality_reject	= 0,
	M3AP_Criticality_ignore	= 1,
	M3AP_Criticality_notify	= 2
} e_M3AP_Criticality;

/* M3AP_Criticality */
typedef long	 M3AP_Criticality_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_M3AP_Criticality_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_Criticality;
extern const asn_INTEGER_specifics_t asn_SPC_Criticality_specs_1;
asn_struct_free_f Criticality_free;
asn_struct_print_f Criticality_print;
asn_constr_check_f Criticality_constraint;
ber_type_decoder_f Criticality_decode_ber;
der_type_encoder_f Criticality_encode_der;
xer_type_decoder_f Criticality_decode_xer;
xer_type_encoder_f Criticality_encode_xer;
oer_type_decoder_f Criticality_decode_oer;
oer_type_encoder_f Criticality_encode_oer;
per_type_decoder_f Criticality_decode_uper;
per_type_encoder_f Criticality_encode_uper;
per_type_decoder_f Criticality_decode_aper;
per_type_encoder_f Criticality_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _M3AP_Criticality_H_ */
#include <asn_internal.h>

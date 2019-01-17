/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-IEs"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#ifndef	_M3AP_MBMS_Service_Area_H_
#define	_M3AP_MBMS_Service_Area_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* M3AP_MBMS-Service-Area */
typedef OCTET_STRING_t	 M3AP_MBMS_Service_Area_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_M3AP_MBMS_Service_Area;
asn_struct_free_f M3AP_MBMS_Service_Area_free;
asn_struct_print_f M3AP_MBMS_Service_Area_print;
asn_constr_check_f M3AP_MBMS_Service_Area_constraint;
ber_type_decoder_f M3AP_MBMS_Service_Area_decode_ber;
der_type_encoder_f M3AP_MBMS_Service_Area_encode_der;
xer_type_decoder_f M3AP_MBMS_Service_Area_decode_xer;
xer_type_encoder_f M3AP_MBMS_Service_Area_encode_xer;
oer_type_decoder_f M3AP_MBMS_Service_Area_decode_oer;
oer_type_encoder_f M3AP_MBMS_Service_Area_encode_oer;
per_type_decoder_f M3AP_MBMS_Service_Area_decode_uper;
per_type_encoder_f M3AP_MBMS_Service_Area_encode_uper;
per_type_decoder_f M3AP_MBMS_Service_Area_decode_aper;
per_type_encoder_f M3AP_MBMS_Service_Area_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _M3AP_MBMS_Service_Area_H_ */
#include <asn_internal.h>

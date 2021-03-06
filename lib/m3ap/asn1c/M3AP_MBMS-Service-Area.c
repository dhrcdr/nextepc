/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-IEs"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#include "M3AP_MBMS-Service-Area.h"

/*
 * This type is implemented using OCTET_STRING,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_M3AP_MBMS_Service_Area_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (4 << 2))
};
asn_TYPE_descriptor_t asn_DEF_M3AP_MBMS_Service_Area = {
	"MBMS-Service-Area",
	"MBMS-Service-Area",
	&asn_OP_OCTET_STRING,
	asn_DEF_M3AP_MBMS_Service_Area_tags_1,
	sizeof(asn_DEF_M3AP_MBMS_Service_Area_tags_1)
		/sizeof(asn_DEF_M3AP_MBMS_Service_Area_tags_1[0]), /* 1 */
	asn_DEF_M3AP_MBMS_Service_Area_tags_1,	/* Same as above */
	sizeof(asn_DEF_M3AP_MBMS_Service_Area_tags_1)
		/sizeof(asn_DEF_M3AP_MBMS_Service_Area_tags_1[0]), /* 1 */
	{ 0, 0, OCTET_STRING_constraint },
	0, 0,	/* No members */
	&asn_SPC_OCTET_STRING_specs	/* Additional specs */
};


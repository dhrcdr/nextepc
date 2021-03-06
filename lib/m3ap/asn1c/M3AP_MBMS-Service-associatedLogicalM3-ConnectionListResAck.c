/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-PDU-Contents"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#include "M3AP_MBMS-Service-associatedLogicalM3-ConnectionListResAck.h"

#include "M3AP_ProtocolIE-Single-Container.h"
static asn_oer_constraints_t asn_OER_type_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..256)) */};
static asn_per_constraints_t asn_PER_type_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_constr_1 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 8,  8,  1,  256 }	/* (SIZE(1..256)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_M3AP_ProtocolIE_Single_Container_1241P1,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_specs_1 = {
	sizeof(struct M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck),
	offsetof(struct M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck = {
	"MBMS-Service-associatedLogicalM3-ConnectionListResAck",
	"MBMS-Service-associatedLogicalM3-ConnectionListResAck",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_tags_1,
	sizeof(asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_tags_1)
		/sizeof(asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_tags_1[0]), /* 1 */
	asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_tags_1,	/* Same as above */
	sizeof(asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_tags_1)
		/sizeof(asn_DEF_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_tags_1[0]), /* 1 */
	{ &asn_OER_type_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_constr_1, &asn_PER_type_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_constr_1, SEQUENCE_OF_constraint },
	asn_MBR_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_1,
	1,	/* Single element */
	&asn_SPC_M3AP_MBMS_Service_associatedLogicalM3_ConnectionListResAck_specs_1	/* Additional specs */
};


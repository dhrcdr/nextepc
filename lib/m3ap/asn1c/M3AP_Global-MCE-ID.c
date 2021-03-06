/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-IEs"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#include "M3AP_Global-MCE-ID.h"

#include "M3AP_ProtocolExtensionContainer.h"
static asn_TYPE_member_t asn_MBR_M3AP_Global_MCE_ID_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct M3AP_Global_MCE_ID, pLMN_Identity),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_M3AP_PLMN_Identity,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"pLMN-Identity"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct M3AP_Global_MCE_ID, mCE_ID),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_M3AP_MCE_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"mCE-ID"
		},
	{ ATF_POINTER, 2, offsetof(struct M3AP_Global_MCE_ID, extendedMCE_ID),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_M3AP_ExtendedMCE_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"extendedMCE-ID"
		},
	{ ATF_POINTER, 1, offsetof(struct M3AP_Global_MCE_ID, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_M3AP_ProtocolExtensionContainer_1289P4,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_M3AP_Global_MCE_ID_oms_1[] = { 2, 3 };
static const ber_tlv_tag_t asn_DEF_M3AP_Global_MCE_ID_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_M3AP_Global_MCE_ID_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pLMN-Identity */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* mCE-ID */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* extendedMCE-ID */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_M3AP_Global_MCE_ID_specs_1 = {
	sizeof(struct M3AP_Global_MCE_ID),
	offsetof(struct M3AP_Global_MCE_ID, _asn_ctx),
	asn_MAP_M3AP_Global_MCE_ID_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_M3AP_Global_MCE_ID_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	4,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_M3AP_Global_MCE_ID = {
	"Global-MCE-ID",
	"Global-MCE-ID",
	&asn_OP_SEQUENCE,
	asn_DEF_M3AP_Global_MCE_ID_tags_1,
	sizeof(asn_DEF_M3AP_Global_MCE_ID_tags_1)
		/sizeof(asn_DEF_M3AP_Global_MCE_ID_tags_1[0]), /* 1 */
	asn_DEF_M3AP_Global_MCE_ID_tags_1,	/* Same as above */
	sizeof(asn_DEF_M3AP_Global_MCE_ID_tags_1)
		/sizeof(asn_DEF_M3AP_Global_MCE_ID_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_M3AP_Global_MCE_ID_1,
	4,	/* Elements count */
	&asn_SPC_M3AP_Global_MCE_ID_specs_1	/* Additional specs */
};


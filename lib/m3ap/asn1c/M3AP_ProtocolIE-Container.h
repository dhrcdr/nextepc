/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "M3AP-Containers"
 * 	found in "../support/r14.1.0/36444-e10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps`
 */

#ifndef	_M3AP_ProtocolIE_Container_H_
#define	_M3AP_ProtocolIE_Container_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct M3AP_MBMSSessionStartRequest_IEs;
struct M3AP_MBMSSessionStartResponse_IEs;
struct M3AP_MBMSSessionStartFailure_IEs;
struct M3AP_MBMSSessionStopRequest_IEs;
struct M3AP_MBMSSessionStopResponse_IEs;
struct M3AP_MBMSSessionUpdateRequest_IEs;
struct M3AP_MBMSSessionUpdateResponse_IEs;
struct M3AP_MBMSSessionUpdateFailure_IEs;
struct M3AP_ErrorIndication_IEs;
struct M3AP_ResetIEs;
struct M3AP_ResetAcknowledgeIEs;
struct M3AP_M3SetupRequestIEs;
struct M3AP_M3SetupResponseIEs;
struct M3AP_M3SetupFailureIEs;
struct M3AP_MCEConfigurationUpdateIEs;
struct M3AP_MCEConfigurationUpdateAcknowledgeIEs;
struct M3AP_MCEConfigurationUpdateFailureIEs;

/* M3AP_ProtocolIE-Container */
typedef struct M3AP_ProtocolIE_Container_1238P0 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionStartRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P0_t;
typedef struct M3AP_ProtocolIE_Container_1238P1 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionStartResponse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P1_t;
typedef struct M3AP_ProtocolIE_Container_1238P2 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionStartFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P2_t;
typedef struct M3AP_ProtocolIE_Container_1238P3 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionStopRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P3_t;
typedef struct M3AP_ProtocolIE_Container_1238P4 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionStopResponse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P4_t;
typedef struct M3AP_ProtocolIE_Container_1238P5 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionUpdateRequest_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P5_t;
typedef struct M3AP_ProtocolIE_Container_1238P6 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionUpdateResponse_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P6_t;
typedef struct M3AP_ProtocolIE_Container_1238P7 {
	A_SEQUENCE_OF(struct M3AP_MBMSSessionUpdateFailure_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P7_t;
typedef struct M3AP_ProtocolIE_Container_1238P8 {
	A_SEQUENCE_OF(struct M3AP_ErrorIndication_IEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P8_t;
typedef struct M3AP_ProtocolIE_Container_1238P9 {
	A_SEQUENCE_OF(struct M3AP_ResetIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P9_t;
typedef struct M3AP_ProtocolIE_Container_1238P10 {
	A_SEQUENCE_OF(struct M3AP_ResetAcknowledgeIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P10_t;
typedef struct M3AP_ProtocolIE_Container_1238P11 {
	A_SEQUENCE_OF(struct M3AP_M3SetupRequestIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P11_t;
typedef struct M3AP_ProtocolIE_Container_1238P12 {
	A_SEQUENCE_OF(struct M3AP_M3SetupResponseIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P12_t;
typedef struct M3AP_ProtocolIE_Container_1238P13 {
	A_SEQUENCE_OF(struct M3AP_M3SetupFailureIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P13_t;
typedef struct M3AP_ProtocolIE_Container_1238P14 {
	A_SEQUENCE_OF(struct M3AP_MCEConfigurationUpdateIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P14_t;
typedef struct M3AP_ProtocolIE_Container_1238P15 {
	A_SEQUENCE_OF(struct M3AP_MCEConfigurationUpdateAcknowledgeIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P15_t;
typedef struct M3AP_ProtocolIE_Container_1238P16 {
	A_SEQUENCE_OF(struct M3AP_MCEConfigurationUpdateFailureIEs) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} M3AP_ProtocolIE_Container_1238P16_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P0;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P0_specs_1;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P0_1[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P0_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P1;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P1_specs_3;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P1_3[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P1_constr_3;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P2;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P2_specs_5;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P2_5[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P2_constr_5;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P3;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P3_specs_7;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P3_7[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P3_constr_7;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P4;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P4_specs_9;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P4_9[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P4_constr_9;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P5;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P5_specs_11;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P5_11[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P5_constr_11;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P6;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P6_specs_13;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P6_13[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P6_constr_13;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P7;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P7_specs_15;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P7_15[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P7_constr_15;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P8;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P8_specs_17;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P8_17[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P8_constr_17;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P9;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P9_specs_19;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P9_19[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P9_constr_19;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P10;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P10_specs_21;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P10_21[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P10_constr_21;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P11;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P11_specs_23;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P11_23[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P11_constr_23;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P12;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P12_specs_25;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P12_25[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P12_constr_25;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P13;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P13_specs_27;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P13_27[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P13_constr_27;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P14;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P14_specs_29;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P14_29[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P14_constr_29;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P15;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P15_specs_31;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P15_31[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P15_constr_31;
extern asn_TYPE_descriptor_t asn_DEF_M3AP_ProtocolIE_Container_1238P16;
extern asn_SET_OF_specifics_t asn_SPC_M3AP_ProtocolIE_Container_1238P16_specs_33;
extern asn_TYPE_member_t asn_MBR_M3AP_ProtocolIE_Container_1238P16_33[1];
extern asn_per_constraints_t asn_PER_type_M3AP_ProtocolIE_Container_1238P16_constr_33;

#ifdef __cplusplus
}
#endif

#endif	/* _M3AP_ProtocolIE_Container_H_ */
#include <asn_internal.h>

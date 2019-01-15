ies = []
ies.append({ "ie_type" : "F-TEID", "ie_value" : "Sender F-TEID for Control Plane", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "TMGI", "ie_value" : "Temporary Mobile Group Identity", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "MBMS Session Duration", "ie_value" : "MBMS Session Duration", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "MBMS Service Area", "ie_value" : "MBMS Service Area", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "MBMS Session Identifier", "ie_value" : "MBMS Session Identifier", "presence" : "C", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is provided by the BM-SC."})
ies.append({ "ie_type" : "MBMS Flow Identifier", "ie_value" : "MBMS Flow Identifier", "presence" : "C", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is provided by the BM-SC."})
ies.append({ "ie_type" : "Bearer QoS", "ie_value" : "QoS profile", "presence" : "M", "instance" : "0", "comment" : "See NOTE 1."})
ies.append({ "ie_type" : "MBMS IP Multicast Distribution", "ie_value" : "MBMS IP Multicast Distribution", "presence" : "M", "instance" : "0", "comment" : "See NOTE 2."})
ies.append({ "ie_type" : "Recovery", "ie_value" : "Recovery", "presence" : "C", "instance" : "0", "comment" : "This IE shall be included if contacting the peer for the first time."})
ies.append({ "ie_type" : "MBMS Time to Data Transfer", "ie_value" : "MBMS Time to Data Transfer", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is received from the BM-SC. "})
ies.append({ "ie_type" : "Absolute Time of MBMS Data Transfer", "ie_value" : "MBMS Data Transfer Start", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be forwarded to the MME if it is received from the BM-SC. "})
ies.append({ "ie_type" : "MBMS Flags", "ie_value" : "MBMS Flags ", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be included if any one of the applicable flags is set to 1.Applicable flags:MBMS Session Re-establishment Indication: this flag shall be set to 1 on the Sm/Sn interfaces if the MBMS Session Start Request message is used to re-establish an MBMS session (see 3GPP TS 23.007 [13])."})
type_list["MBMS IP Multicast Distribution"]["max_instance"] = "1"
ies.append({ "ie_type" : "MBMS IP Multicast Distribution", "ie_value" : "MBMS Alternative IP Multicast Distribution", "presence" : "CO", "instance" : "1", "comment" : "If the MBMS GW supports both IPv4 and IPv6 M1 multicast address types, the MBMS GW may include this IE on the Sm interface to provide an alternative MBMS IP Multicast Distribution Address with a different address type (i.e. IPv4 or IPv6) than the one provided in the MBMS IP Multicast Distribution IE.See NOTE 2."})
ies.append({ "ie_type" : "ECGI List", "ie_value" : "MBMS Cell List", "presence" : "CO", "instance" : "0", "comment" : "The MBMS GW shall include this IE on the Sm interface if a MBMS Cell List was received from the BM-SC.See NOTE 3."})
msg_list[key]["ies"] = ies

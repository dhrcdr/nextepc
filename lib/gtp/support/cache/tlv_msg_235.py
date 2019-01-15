ies = []
ies.append({ "ie_type" : "MBMS Flow Identifier", "ie_value" : "MBMS Flow Identifier", "presence" : "C", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is provided by the BM-SC. See NOTE 1."})
ies.append({ "ie_type" : "Absolute Time of MBMS Data Transfer", "ie_value" : "MBMS Data Transfer Stop", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be forwarded to the MME if it is received from the BM-SC. "})
ies.append({ "ie_type" : "MBMS Flags", "ie_value" : "MBMS Flags ", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be included if any one of the applicable flags is set to 1.Applicable flags:Local MBMS Bearer Context Release Indication: this flag shall be set to 1 on the Sm/Sn interfaces if the MBMS Session Stop Request message is used to release  the MBMS bearer context locally in the MME/SGSN (see 3GPP TS 23.007 [13])."})
msg_list[key]["ies"] = ies

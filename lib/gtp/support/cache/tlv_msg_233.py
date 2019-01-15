ies = []
ies.append({ "ie_type" : "MBMS Service Area", "ie_value" : "MBMS Service Area", "presence" : "C", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is provided by the BM-SC."})
ies.append({ "ie_type" : "TMGI", "ie_value" : "Temporary Mobile Group Identity", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "F-TEID", "ie_value" : "Sender F-TEID for Control Plane", "presence" : "O", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "MBMS Session Duration", "ie_value" : "MBMS Session Duration", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "Bearer QoS", "ie_value" : "QoS profile", "presence" : "M", "instance" : "0", "comment" : "See NOTE 1."})
ies.append({ "ie_type" : "MBMS Session Identifier", "ie_value" : "MBMS Session Identifier", "presence" : "C", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is provided by the BM-SC."})
ies.append({ "ie_type" : "MBMS Flow Identifier", "ie_value" : "MBMS Flow Identifier", "presence" : "C", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is provided by the BM-SC."})
ies.append({ "ie_type" : "MBMS Time to Data Transfer", "ie_value" : "MBMS Time to Data Transfer", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be forwarded to MME/SGSN if it is provided by the BM-SC. "})
ies.append({ "ie_type" : "Absolute Time of MBMS Data Transfer", "ie_value" : "MBMS Data Transfer Start", "presence" : "CO", "instance" : "0", "comment" : "This IE shall be forwarded to the MME if it is received from the BM-SC. "})
ies.append({ "ie_type" : "ECGI List", "ie_value" : "MBMS Cell List", "presence" : "CO", "instance" : "0", "comment" : "The MBMS GW shall include this IE on the Sm interface if a MBMS Cell List was received from the BM-SC.See NOTE 2. "})
msg_list[key]["ies"] = ies

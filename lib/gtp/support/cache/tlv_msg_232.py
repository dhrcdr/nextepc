ies = []
ies.append({ "ie_type" : "Cause", "ie_value" : "Cause", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "F-TEID", "ie_value" : "Sender F-TEID for Control Plane", "presence" : "M", "instance" : "0", "comment" : ""})
ies.append({ "ie_type" : "MBMS Distribution Acknowledge", "ie_value" : "MBMS Distribution Acknowledge", "presence" : "C", "instance" : "0", "comment" : "This IE shall be included on the Sn interface."})
ies.append({ "ie_type" : "F-TEID", "ie_value" : "Sn-U SGSN F-TEID", "presence" : "C", "instance" : "1", "comment" : "This IE shall be included on the Sn interface if some RNCs have not accepted IP multicast distribution."})
ies.append({ "ie_type" : "Recovery", "ie_value" : "Recovery", "presence" : "C", "instance" : "0", "comment" : "This IE shall be included if contacting the peer for the first time."})
msg_list[key]["ies"] = ies

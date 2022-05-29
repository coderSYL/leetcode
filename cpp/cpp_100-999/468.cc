// C++
// leetcode 468
// https://leetcode.cn/problems/validate-ip-address/

class Solution {
public:
	bool is_good_char(char c) {
		if(c >= '0' && c <= '9')
			return true;
		if(c >= 'a' && c <= 'f')
			return true;
		if(c >= 'A' && c <= 'F')
			return true;
		return false;
	}

    string validIPAddress(string queryIP) {
    	int cnt_dot = 0, cnt_colon = 0, n = queryIP.size();
    	// 统计
    	for(int i = 0; i < n; ++i) {
    		switch(queryIP[i]) {
    			case '.' : cnt_dot++;
    				break;
    			case ':' : cnt_colon++;
    				break;
    		}
    	}
    	if(cnt_dot != 3 && cnt_colon != 7)
    		return "Neither";
    	// check if it's Ipv4
    	if(cnt_dot == 3) {
    		if(cnt_colon > 0)
    			return "Neither";
    		int cur = 0;
    		for(int i = 0; i < n; ++i) {
    			if(queryIP[i] == '.') {
    				if(i == 0 || queryIP[i-1] == '.' || i == n-1)
    					return "Neither";
    				cur = 0;
    				continue;
    			}
    			int u = queryIP[i] - '0';
    			if(u < 0 || u > 9)
    				return "Neither";
    			if(cur == 0 && u == 0 && i != n-1 && queryIP[i+1] != '.')
    				return "Neither";
    			cur = cur*10 + u;
                if(cur > 255)
                    return "Neither";
    		}
    		return "IPv4";
    	}
    	// check if it's IPv6
    	if(cnt_dot > 0)
    		return "Neither";
    	int num_len = 0;
    	for(int i = 0; i < n; ++i) {
    		if(queryIP[i] == ':') {
    			if(num_len > 4 || num_len <= 0)
    				return "Neither";
    			num_len = 0;
    			continue;
    		}
    		if(!is_good_char(queryIP[i]))
    			return "Neither";
    		num_len++;
    	}
    	if(num_len > 4 || num_len <= 0)
    		return "Neither";
    	return "IPv6";
    }
};
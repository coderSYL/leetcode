// C++
// leetcode 929
// https://leetcode.cn/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
    	set<string> tmp;
    	for(auto &s : emails) {
    		int n = s.size(), p = 0;
    		char after[n];
    		bool get_at = false;
    		for(int i = 0; i < n; ++i) {
    			char c = s[i];
    			if(get_at) {
    				after[p++] = c;
    			} else if(c == '.') {
    				continue;
    			} else if(c == '+') {
    				while(s[i+1] != '@')
    					++i;
    				continue;
    			} else if(c == '@') {
    				get_at = true;
    				after[p++] = c;
    			} else {
    				after[p++] = c;
    			}
    		}
    		tmp.insert(string(after, after + p));
    	}
    	return tmp.size();
    }
};
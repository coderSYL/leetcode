// C++
// leetcode 44
// https://leetcode-cn.com/problems/wildcard-matching/
// 平面dp

class Solution {
public:
    bool isMatch(string s, string p) {
    	bool f[s.size() + 1][p.size() + 1];
    	memset(f, 0, sizeof(f));
    	f[0][0] = true;

    	for(int i = 0; i < p.size(); i++) {
    		char c = p[i];
    		if(c == '?') {
    			for(int j = 0; j < s.size(); j++) {
    				if(f[j][i])
    					f[j + 1][i + 1] = true;
    			}
    		} else if(c == '*') {
    			int j = 0;
    			while(j <= s.size() && !f[j][i])
    				j++;
    			for(; j <= s.size(); j++) {
    				f[j][i + 1] = true;
    			}
    		} else {
    			// 英文字母情况
    			for(int j = 0; j < s.size(); j++) {
    				if(f[j][i] && s[j] == c)
    					f[j + 1][i + 1] = true;
    			}
    		}
    	}
    	return	f[s.size()][p.size()];
    }
};
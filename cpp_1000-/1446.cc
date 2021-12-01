// C++
// leetcode 1446
// https://leetcode-cn.com/problems/consecutive-characters/

class Solution {
public:
    int maxPower(string s) {
    	int res = 1, cnt = 1;
    	for(int i = 1; i < s.size(); i++) {
    		if(s[i] == s[i - 1]) {
    			cnt++;
    		} else {
    			res = max(res, cnt);
    			cnt = 1;
    		}
    	}
    	return max(res, cnt);
    }
};
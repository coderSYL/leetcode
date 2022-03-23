// C++
// leetcode 1576
// https://leetcode-cn.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/

class Solution {
public:
    string modifyString(string s) {
    	int n = s.size();
    	vector<char> tmp(n);
    	// 填装tmp[i]
    	for(int i = 0; i < n; ++i) {
    		if(s[i] != '?') {
    			tmp[i] = s[i];
    			continue;
    		}
    		char pre = (i == 0 ? '1': tmp[i - 1]);
    		char after = (i == n-1 ? '1' : s[i + 1]);
    		if(pre == 'a' || after == 'a') {
    			if(pre == 'b' || after == 'b') tmp[i] = 'c';
    			else tmp[i] = 'b';
    		} else {
    			tmp[i] = 'a';
    		}
    	}
    	return string(tmp.begin(), tmp.end());
    }
};
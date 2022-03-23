// C++
// leetcode 917
// https://leetcode-cn.com/problems/reverse-only-letters/

class Solution {
public:
	bool isLetter(char& c) {
		if(c >= 'a' && c <='z') return true;
		if(c >= 'A' && c <='Z') return true;
		return false;
	}
    string reverseOnlyLetters(string s) {
    	int n = s.size();
    	int l = 0, r = n-1;
    	vector<char> tmp(n);
    	while(l <= r){
    		while(l <= r && !isLetter(s[l])) {
    			tmp[l] = s[l];
    			l++;
    		}
    		// 至此s[l]是字母
    		while(l <= r && !isLetter(s[r])) {
    			tmp[r] = s[r];
    			r--;
    		}
    		if(l <= r) {
    			tmp[l] = s[r];
    			tmp[r] = s[l];
    		}
    		l++, r--;
    	}
    	return string(tmp.begin(), tmp.end());
    }
};
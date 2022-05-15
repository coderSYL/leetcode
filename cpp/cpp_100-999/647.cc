// C++
// leetcode 647
// https://leetcode.cn/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
    	int n = s.size();
    	int res = 0;
    	for(int i = 0; i < n; i++) {
    		// 奇数长度子串
    		int l = i, r = i;
    		while(l >= 0 && r < n && s[l] == s[r]) {
    			l--; r++;
    			res++;
    		}
    		// 偶数长度子串
    		l = i; r = i+1;
    		while(l >= 0 && r < n && s[l] == s[r]) {
    			l--; r++;
    			res++;
    		}
    	}
    	return res;
    }
};
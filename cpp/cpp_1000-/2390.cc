// C++
// leetcode 2390
// https://leetcode.cn/problems/removing-stars-from-a-string/

class Solution {
public:
    string removeStars(string s) {
        int n = s.size(), p = 0;
        vector<char> tmp(n);
        for (int i = 0; i < n; i++) {
        	if (s[i] == '*') {
        		p--;
        	} else {
        		tmp[p++] =  s[i];
        	}
        }
        if (p == 0)
        	return "";
        tmp.resize(p);
        return string(tmp.begin(), tmp.end());
    }
};
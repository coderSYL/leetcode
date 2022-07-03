// C++
// leetcode 1750
// https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution {
public:
    int minimumLength(string s) {
    	int n = s.size(), start = 0, end = n - 1;
    	char c;
    	while (start < end) {
    		if(s[start] != s[end])
    			break;
    		c = s[start];
    		int l = start, r = end;
    		while (l <= r && s[l] == c) {
    			l++;
    		}
    		while (l <= r && s[r] == c) {
    			r--;
    		}
            start = l;
            end = r;
    	}
        return end - start + 1;
    }
};
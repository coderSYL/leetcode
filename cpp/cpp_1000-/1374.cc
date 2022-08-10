// C++
// leetcode 1374
// https://leetcode.cn/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution {
public:
    string generateTheString(int n) {
    	if ((n & 1) == 1) {
    		// odd
    		return string(n, 'a');
    	}
    	return "a" + string(n-1, 'b');
    }
};
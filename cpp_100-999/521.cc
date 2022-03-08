// C++
// leetcode 521
// https://leetcode-cn.com/problems/longest-uncommon-subsequence-i/

class Solution {
public:
    int findLUSlength(string a, string b) {
    	if(a == b) return -1;
    	return (a.size() > b.size() ? (int)a.size() : (int)b.size());
    }
};
// C++
// leetcode 2351
// https://leetcode.cn/problems/first-letter-to-appear-twice/

class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) {
        	int u = c - 'a';
        	if (++cnt[u] == 2)
        		return c;
        }
        return '-';
    }
};
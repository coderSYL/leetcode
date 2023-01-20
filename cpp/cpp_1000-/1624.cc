// C++
// leetcode 1624
// https://leetcode.cn/problems/largest-substring-between-two-equal-characters/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
    	int first[26];
    	int last[26];
    	memset(first, -1, sizeof(first));
    	memset(last, -1, sizeof(last));
    	int n = s.size();
    	for (int i = 0; i < n; i++) {
    		int u = s[i] - 'a';
    		if (first[u] == -1)
    			first[u] = i;
    		last[u] = i;
    	}
    	int res = -1;
    	for (int i = 0; i < 26; i++) {
    		res = max(last[i] - first[i] - 1, res);
    	}

    	return res;
    }
};
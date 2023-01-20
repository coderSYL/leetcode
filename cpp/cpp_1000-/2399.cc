// C++
// leetcode 2399
// https://leetcode.cn/problems/check-distances-between-same-letters/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        bool vis[26];
        memset(vis, 0, sizeof(vis));
        int n = s.size();
        for (int i = 0; i < n; i++) {
        	int u = s[i] - 'a';
        	if (vis[u]) {
        		if (distance[u] != i)
        			return false;
        	} else {
        		vis[u] = true;
        		distance[u] += i + 1;
        	}
        }
        return true;
    }
};
// C++
// leetcode 1719
// https://leetcode-cn.com/problems/number-of-ways-to-reconstruct-a-tree/
// 思路方法偷三叶的

class Solution {
public:
	int checkWays(vector<vector<int>>& pairs) {
		bool g[510][510];
		int cnt[510] = {0};
		memset(g, 0, sizeof(g));
		int m = pairs.size();
		set<int> set;
		for (auto & p : pairs) {
			int a = p[0], b = p[1];
			g[a][b] = true;
			g[b][a] = true;
			cnt[a]++;
			cnt[b]++;
			set.insert(a);
			set.insert(b);
		}
		vector<int> v(set.begin(), set.end());
		auto cmp = [&](int a, int b) {return cnt[a] > cnt[b];};
		sort(v.begin(), v.end(), cmp);
		int n = set.size(), root = v[0];
		if (m < n - 1) return 0;
		int fa[510] = {0};
		fa[root] = -1;
		for (int i = 1; i < n; i++) {
			int a = v[i];
			bool ok = false;
			for (int j = i - 1; j >= 0 && !ok; j--) {
				int b = v[j];
				if (g[a][b]) {
					fa[a] = b;
					ok = true;
				}
			}
			if (!ok) return 0;
		}
		int c = 0, res= 1;
		for(auto & i : set) {
			int j = i;
			while (fa[j] != -1) {
                if (!g[i][fa[j]]) return 0;
                if (cnt[i] == cnt[fa[j]]) res = 2;
                c++;
                j = fa[j];
            }
		}
		return (c < m ? 0 : res);
	}
};
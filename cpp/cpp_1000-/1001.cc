// C++
// leetcode 1001
// https://leetcode-cn.com/problems/grid-illumination/
// 时空间都很拉的屑方法

class Solution {
public:
	map<int, set<long>> row, col, sum, diff;
	// vector<set<long>> row, col, sum, diff;
	int n_;
	long getId(int x, int y) {
		long id = x;
		id = id * ((long)1e9 + 10) + y;
		return id;
	}

	bool check(int x, int y) {
		if (!row[x].empty()) return true;
		if (!col[y].empty()) return true;
		if (!sum[x + y].empty()) return true;
		if (!diff[x - y + n_].empty()) return true;
		return false;
	}

	void regist(int x, int y) {
		long id = getId(x, y);
		row[x].insert(id);
		col[y].insert(id);
		sum[x + y].insert(id);
		diff[x - y + n_].insert(id);
	}

	void unregist(int x, int y) {
		for (int i = max(x - 1, 0); i < min(x + 2, n_); i++) {
			for (int j = max(y - 1, 0); j < min(y + 2, n_); j++) {
				long id = getId(i, j);
				row[i].erase(id);
				col[j].erase(id);
				sum[i + j].erase(id);
				diff[i - j + n_].erase(id);
			}
		}
	}

	vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
		n_ = n;

		for (auto& two : lamps) {
			regist(two[0], two[1]);
		}
		int m = queries.size();
		vector<int> res(m);
		for (int i = 0; i < m; i++) {
			int x = queries[i][0], y = queries[i][1];
			res[i] = (check(x, y) ? 1 : 0);
			unregist(x, y);
		}
		return res;
	}
};
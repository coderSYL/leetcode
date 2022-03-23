// C++
// leetcode 216
// https://leetcode-cn.com/problems/combination-sum-iii/
// 简简单单dfs

class Solution {
public:
	vector<int> now;
	int sum = 0;
	int target;
	vector<vector<int>> res;
	void dfs(int u, int left) {
		if(left == 0) {
			if(sum == target) {
				res.push_back(now);
			}
			return;
		}
		if(u == 10) return;
		if(sum > target) return;
		now.push_back(u);
		sum += u;
		dfs(u + 1, left - 1);
		sum -= u;
		now.pop_back();
		dfs(u + 1, left);
	}

    vector<vector<int>> combinationSum3(int k, int n) {
    	target = n;
    	dfs(1, k);
    	return res;
    }
};
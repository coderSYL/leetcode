// C++
// leetcode 90
// https://leetcode-cn.com/problems/subsets-ii/

class Solution {
public:
	int size = 0;
	map<int, int>	cnt;
	vector<vector<int>>	res;
	vector<int> cur;
	void dfs(vector<int>& nums, int u) {
		if(u == size) {
			res.push_back(cur);
			return;
		}
		int m = nums[u];
		int n = cnt[m];
		cur.insert(cur.end(), n, m);
		dfs(nums, u + 1);
		while(n--) {
			cur.pop_back();
			dfs(nums, u + 1);
		}
	}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	for(auto x : nums)
    		cnt[x]++;
    	for(auto [k, v] : cnt)
    		nums[size++] = k;
        dfs(nums, 0);
        return res;
    }
};
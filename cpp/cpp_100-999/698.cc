// C++
// leetcode 698
// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
	vector<int> cur;
	int target = 0;

	bool dfs(vector<int>& nums, int u) {
		if(u == nums.size())
			return true;
		int val = nums[u];
		for(int i = 0; i < cur.size(); ++i) {
			bool jump = false;
			for(int j = 0; j < i; ++j)
				if(cur[i] == cur[j]) {
					jump = true;
					break;
				}
			if(jump)
				continue;
			cur[i] += val;
			if(cur[i] <= target && dfs(nums, u+1))
				return true;
			cur[i] -= val;
		}
		return false;
	}

    bool canPartitionKSubsets(vector<int>& nums, int k) {
    	for(auto x : nums)
    		target += x;
    	if(target % k != 0)
    		return false;
    	target /= k;
    	cur.resize(k, 0);
    	sort(nums.begin(), nums.end(), greater<int>());
    	if(nums[0] > target)
    		return false;
    	return dfs(nums, 0);
    }
};
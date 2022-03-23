// C++
// leetcode 2044
// https://leetcode-cn.com/problems/count-number-of-maximum-bitwise-or-subsets/

class Solution {
public:
	int res = 0;
	void dfs(vector<int>& nums, int u, int cur, int target) {
		if(u == nums.size())
			return;
		if((cur | nums[u]) == target)
			res++;
		dfs(nums, u+1, cur|nums[u], target);
		dfs(nums, u+1, cur, target);
	}
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(auto &x : nums)
        	target |= x;
        dfs(nums, 0, 0, target);
        return res;
    }
};
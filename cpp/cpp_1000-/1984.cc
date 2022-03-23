// C++
// leetcode 1984
// https://leetcode-cn.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
    	sort(nums.begin(), nums.end());
    	int n = nums.size();
    	int res = INT_MAX;
    	for(int i = 0; i <= n - k; i++) {
    		res = min(res, nums[i + k - 1] - nums[i]);
    	}
    	return res;
    }
};
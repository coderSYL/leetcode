// C++
// leetcode 164
// https://leetcode-cn.com/problems/maximum-gap/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int res = 0;
    	for(int i = 1; i < nums.size(); i++)
    		res = max(res, nums[i] - nums[i - 1]);
    	return res;
    }
};
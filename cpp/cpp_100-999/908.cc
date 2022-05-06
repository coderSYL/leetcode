// C++
// leetcode 908
// https://leetcode-cn.com/problems/smallest-range-i/

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
    	int max_cur = nums[0], min_cur = nums[0];
    	for(auto & x : nums) {
    		max_cur = max(x, max_cur);
    		min_cur = min(x, min_cur);
    	}
    	return max(0, max_cur - min_cur - 2 * k);
    }
};
// C++
// leetcode 1827
// https://leetcode.cn/problems/minimum-operations-to-make-the-array-increasing/

class Solution {
public:
    int minOperations(vector<int>& nums) {
    	int res = 0;
    	int cur = nums[0], n = nums.size();
    	for (int i = 1; i < n; i++) {
    		if (nums[i] <= cur) {
    			res += ++cur - nums[i];
    		} else {
    			cur = nums[i];
    		}
    	}
    	return res;
    }
};
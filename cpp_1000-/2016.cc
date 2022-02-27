// C++
// leetcode 2016
// https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = -1;
        int minNow = nums[0];
        for(int i = 1; i < n; i++) {
        	res = max(res, nums[i] - minNow);
        	minNow = min(minNow, nums[i]);
        }
        return (res > 0 ? res : -1);
    }
};
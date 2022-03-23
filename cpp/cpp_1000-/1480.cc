// C++
// leetcode 1480
// https://leetcode-cn.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0];
        for(int i = 1; i < n; i++) {
            nums[i] += cur;
            cur = nums[i];
        }
        return  nums;
    }
};
// C++
// leetcode 1752
// https://leetcode.cn/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        int upTime = 0, n = nums.size();
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1])
                upTime++;
            if(upTime > 1)
                return false;
        }
        if (upTime == 1) {
                return nums[n-1] <= nums[0];
        }
        return true;
    }
};
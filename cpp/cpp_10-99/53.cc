/*
 * C++
 * leetcode 53
 * url: https://leetcode-cn.com/problems/maximum-subarray/
 * 经典dp
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size =nums.size(), min = 0, ret = nums[0];
        int sum = 0;
        for(int i =0; i<size; i++){
            sum +=  nums[i];
            if(sum-min >ret)
                ret = sum-min;
            if(sum<min)
                min = sum;
        }
        return ret;
    }
};
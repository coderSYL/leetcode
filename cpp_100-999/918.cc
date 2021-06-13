/*
 * C++
 * leetcode 918
 * url: https://leetcode-cn.com/problems/maximum-sum-circular-subarray/
 * 先用前缀和算不跨界的max
 * 再用前缀和反向遍历，配合 所有和total来计算跨界的max，就能覆盖所有情况
 */

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int size =nums.size() , ret = INT_MIN, temp =0, min = 0;
        int sum[size+1];
        sum[0] = 0;
        for(int i =1; i<=size; i++){
            sum[i] = sum[i-1]+nums[i-1];
            if(sum[i]-min>ret)
                ret = sum[i]-min;
            if(sum[i]<min)
                min = sum[i];
        }
        // 至此，ret中存的是不跨界的max
        // 下面是搞跨界的
        // 从后往前轮询一遍，并且存储最小的sum[i]
        // 对于i<j，从j到i的和 = sum[i] +total -sum[j]
        int total = sum[size];
        min = sum[size-1];
        for(int i =size-1; i>=0; i--){
            if(sum[i]+total-min >ret)
                ret = sum[i]+total-min;
            if(sum[i] <min)
                min = sum[i];
        }
        return ret;
    }
};
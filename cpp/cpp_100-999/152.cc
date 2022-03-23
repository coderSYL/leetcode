/*
 * C++
 * leetcode 152
 * url: https://leetcode-cn.com/problems/maximum-product-subarray/
 * dp[i]表示以nums[i]为起点的子数组的乘积
 * 数组中每个位置都可能产生最终ret
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size =nums.size() , ret = INT_MIN, temp =0;
        int dp[size];
        for(int i =0; i<size; i++){
            dp[i] = 1;
            temp = nums[i];
            for(int j = 0; j<=i; j++){
                dp[j] *=temp;
                if(dp[j]>ret)
                    ret = dp[j];
            }
        }
        return ret;
    }
};
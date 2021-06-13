/*
 * C++
 * leetcode 801
 * url: https://leetcode-cn.com/problems/minimum-swaps-to-make-sequences-increasing/
 * 
 */

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int dp[nums1.size()][2];
        dp[0][0] = 0;
        dp[0][1] = 1;
        for(int i = 1;i < nums1.size();i++)
        {
            if(nums1[i-1]<nums1[i]&&nums2[i-1]<nums2[i]){
                if(nums1[i-1]<nums2[i] && nums2[i-1]<nums1[i]){//任意交换或者不交换，取最优值
                    dp[i][0] = min(dp[i-1][0],dp[i-1][1]);
                    dp[i][1] = min(dp[i-1][0],dp[i-1][1])+1;
                }else{
                    dp[i][0] = dp[i-1][0];//不交换，则上个位置也不能交换
                    dp[i][1] = dp[i-1][1]+1; //交换，则上个位置也必须交换
                }
            }else{
                dp[i][0] = dp[i-1][1];// 不交换，则上个位置必须交换
                dp[i][1] = dp[i-1][0]+1;// 交换，则上个位置不能交换
            }
        }
        return min(dp[nums1.size()-1][0],dp[nums1.size()-1][1]);
    }
};
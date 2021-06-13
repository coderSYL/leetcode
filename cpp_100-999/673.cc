/*
 * C++
 * leetcode 673
 * url: https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
 * 300的加强版，统计最长增序列的个数
 * 延续300的思路，用dp[i]记录以i号位为结尾的最长序列长度
 * 新增n[i]数组记录符合dp[i]的序列的个数
 * 遍历nums[i]，如果刷新了dp[i]，则重置ret_num 为n[i]，如果与之前的最大dp相等，则 ret_num += n[i]
 */

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size =nums.size(), ret = 1, temp = 0, tt, ret_num = 1;
        int dp[size], n[size];
        dp[0] = 1;
        n[0] = 1;
        for(int i = 1; i<size; i++){
            tt = 1;
            temp = nums[i];
            dp[i] = 1;
            for(int j =0; j<i; j++){
                if(temp>nums[j] && dp[j]>=dp[i]){
                    dp[i] = dp[j]+1;
                    tt = n[j];
                }else if( temp>nums[j] && dp[i]-1 ==dp[j]){
                    tt += n[j];
                }
            }
            n[i] = tt;
            if(dp[i]>ret){
                ret =dp[i];
                ret_num = tt;
            }else if(dp[i]==ret){
                ret_num += tt;
            }
            // cout<< i<<","<< dp[i]<<","<<n[i]<<endl;
        }
        return ret_num;
    }
};
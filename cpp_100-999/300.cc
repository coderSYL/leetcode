// C++
// leetcode 300
// https://leetcode-cn.com/problems/longest-increasing-subsequence/
// dp[i]用来存储以nums[i]为结尾的最长子序列的大小
// 遍历求一遍dp[0] ~ dp[size-1]
// max(dp[0], ... , dp[size-1])就是答案
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	int size =nums.size(), ret = 1, temp = 0;
    	int dp[size];
    	dp[0] = 1;
    	for(int i = 1; i<size; i++){
    		temp = nums[i];
    		dp[i] = 1;
    		for(int j =0; j<i; j++){
    			if(temp>nums[j] && dp[j]>=dp[i]){
    				dp[i] = dp[j]+1;
    			}
    		}
    		if(dp[i]>ret)
    			ret =dp[i];
    	}
    	return ret;
    }
};
/*
 * C++
 * leetcode 494
 * url: https://leetcode-cn.com/problems/target-sum/
 * dp[i][j]，表示到了第i位时能使结果为 j-total 的方法有多少种
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    	int total =0, size = nums.size();
    	for(auto x:nums){
    		total +=x;
    	}
    	// 够不着的情况
		if(total<target || target<-total)
			return 0;
		// 开始dp
    	int dp[size+1][2*total+1];
    	memset(dp, 0, sizeof(dp));	// 全设为0
    	dp[0][total] =1;
    	for(int i =1; i<= size; i++){
    		int temp = nums[i-1];
    		for(int j =-total; j<=total;j++){
    			if( j-temp+total >=0)
    				dp[i][j+total] += dp[i-1][j-temp+total];
    			if( j+temp+total <= 2*total)
    				dp[i][j+total] += dp[i-1][j+temp+total];
    		}
    	}
    	return dp[size][target+total];
    }
};
// C++
// leetcode 70
// https://leetcode-cn.com/problems/climbing-stairs/
// 经典dp

class Solution {
public:
    int climbStairs(int n) {
    	int dp[n+1];
    	dp[0] = 1;
    	dp[1] = 1;
    	for(int i = 2; i <= n; ++i)
    		dp[i] = dp[i-1] +dp[i-2];
    	return dp[n];
    }
};
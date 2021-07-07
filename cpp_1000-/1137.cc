// C++
// leetcode 1137
// https://leetcode-cn.com/problems/n-th-tribonacci-number/
// 经典dp

class Solution {
public:
    int tribonacci(int n) {
    	int m = max(n + 1, 3);
    	int dp[m];
    	dp[0] = 0;
    	dp[1] = 1;
    	dp[2] = 1;
    	for(int i = 3; i <= n; ++i)
    		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    	return dp[n];
    }
};
// C++
// leetcode 198
// https://leetcode-cn.com/problems/house-robber/
// 动态规划， int型数组 记录返回值

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0)
            return 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[n];
    }
};
// C++
// leetcode 45
// https://leetcode-cn.com/problems/jump-game-ii/
// DP + 贪心 + 双指针

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = 0;
        for(int i = 1, j = 0; i < n; ++i) {
            while(j + nums[j] < i)  j++;
            dp[i] = dp[j] + 1;
        }
        return dp[n - 1];
    }
};
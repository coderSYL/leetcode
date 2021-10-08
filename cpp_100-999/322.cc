// C++
// leetcode 322
// https://leetcode-cn.com/problems/coin-change/
// 


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, INT_MAX);
        int dp[amount + 1];     // 事实证明，数组快一些
        for(auto& x : dp)
            x = INT_MAX;    // 用INT_MAX指代到不了的总额，初始化时都到不了
        dp[0] = 0;

        // 给coins排队
        sort(coins.begin(), coins.end());

        // 从面额大的硬币开始
        for(int i = coins.size() - 1; i >= 0; i--) {
            // 本次选的硬币面额
            int val = coins[i];
            // 刷新dp用的数组
            for(int j = val; j <= amount; j++)
                dp[j] = min(dp[j], (dp[j - val] == INT_MAX ? INT_MAX : dp[j - val] + 1));
        }


        return  (dp[amount] == INT_MAX ? -1 : dp[amount]);
    }
};
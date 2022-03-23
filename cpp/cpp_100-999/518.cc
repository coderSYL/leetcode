// C++
// leetcode 518
// https://leetcode-cn.com/problems/coin-change-2/
// 经典dp

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int coin_val : coins){
            for(int i = coin_val; i <= amount; i++){
                dp[i] += dp[i - coin_val];
            }
        }
        return dp[amount];
    }
};
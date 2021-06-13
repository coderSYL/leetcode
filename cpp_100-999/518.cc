/*
 * C++
 * leetcode 518
 * url: https://leetcode-cn.com/problems/coin-change-2/
 * 以[0, amount]搞dp
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int i = 0;
        for(int coin:coins){
            for(int i =coin; i<=amount; i++){
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
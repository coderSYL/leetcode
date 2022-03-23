// C++
// leetcode 877
// https://leetcode-cn.com/problems/stone-game/
// 必胜法
// 或者dp

// 必胜法
// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//     	return true;
//     }
// };

// dp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int dp[n + 1][n + 1]; // dp[l][r]表示从[l,r)中取，先手会比后手多几个
        for(int r = 0; r <= n; r++) {
            // 每轮填入dp[x][r]
            dp[r][r] = 0;
            for(int l = r - 1; l >= 0; l--) {
                // 填入dp[l][r]
                if(((r - l) & 1) == 0) {
                    // 偶数个，由奇数个衍生过来，要减
                    dp[l][r] = max(dp[l][r - 1] - piles[r - 1], dp[l + 1][r] - piles[l]);
                } else {
                    // 奇数个，由偶数个衍生过来
                    dp[l][r] = max(dp[l][r - 1] + piles[r - 1], dp[l + 1][r] + piles[l]);
                }
                
            }
        }
        return dp[0][n] > 0 ; 
    }
};
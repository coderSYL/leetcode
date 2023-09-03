// C++
// leetcode 1289
// https://leetcode-cn.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(grid[0]);
        for(int i = 1; i < n; i++) {
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            int min1pos = -1;
            for(int j = 0; j < n; j++) {
                if(dp[j] <= min1) {
                    min2 = min1;
                    min1 = dp[j];
                    min1pos = j;
                } else if(dp[j] < min2) {
                    min2 = dp[j];
                }
            }
            for(int j = 0; j < n; j++) {
                if(j == min1pos) {
                    dp[j] = grid[i][j] + min2;
                } else {
                    dp[j] = grid[i][j] + min1;
                }
            }
        }
        int res = INT_MAX;
        for(auto x : dp)
            res = min(res, x);
        return  res;
    }
};
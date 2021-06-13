/*
 * C++
 * leetcode 279
 * url: https://leetcode-cn.com/problems/perfect-squares/
 * 经典dp
 */

class Solution {
public:
    // 返回数的平方为不超过be的最大的平方数
    int low_Sqrt(int be){
        int ret =1;
        while(ret*ret <= be)
            ret++;
        ret--;
        return ret;
    }

    int numSquares(int n) {
        // create dp and initialize it
        int dp[n+1];
        dp[0] = 0;
        for(int i =1; i<=n; i++)
            dp[i] = INT_MAX;
        // determinate the last num
        int END = low_Sqrt(n);
        // do the dp
        for(int i =1; i<=END; i++){
            int caree = i*i;
            for(int j =caree; j<=n; j++){
                dp[j] = min(dp[j], dp[j-caree]+1);
            }
        }
        return dp[n];
    }
};
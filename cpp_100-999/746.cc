/*
 * C++
 * leetcode 746
 * url: https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 * 经典dp
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size =cost.size();
        int dp[size+1];
        dp[0] = 0;
        dp[1] = 0;
        for(int i =2; i<=size; i++){
            dp[i] = min( dp[i-1]+cost[i-1], dp[i-2] +cost[i-2]);
        }
        return dp[size];
    }
};
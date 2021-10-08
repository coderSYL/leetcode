// C++
// leetcode 1155
// https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/
// 


class Solution {
public:
    int MOD = (int)1e9 + 7;

    int numRollsToTarget(int d, int f, int target) {
        if(target > d * f || target < d)
            return  0;
        // 定义 dp[i] 表示掷骰子和为i的可能性
        // 初始化，第一次完事的情况，即和为 1 到 f 的可能种类为1，其他都为0
        int dp[d * f + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= f; i++)
            dp[i] = 1;

        
        int done = 1;   // 已经做完的次数，目前一次
        while(done < d) {
            done++;
            int startPointForThisLoop = done * f;   // 从最大能到达的点来算
            for(int i = startPointForThisLoop; i > 0; i--) {
                dp[i] = 0;
                for(int j = 1; j <= f; j++) {
                    if(i - j == 0)
                        break;
                    dp[i] += dp[i - j];
                    dp[i] %= MOD;
                }
            }
        }
        return  dp[target];
    }
};
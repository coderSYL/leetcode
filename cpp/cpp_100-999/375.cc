// C++
// leetcode 375
// https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/
// dp

// test
class Solution {
public:
    int getMoneyAmount(int n) {
        int cache[n + 1][n + 1];
        for(int i = 1; i <= n; i++) {
            // 每轮算出cache[x][i]的所有值
            cache[i][i] = 0;
            for(int j = i - 1; j > 0; j--) {
                // 本轮确定cache[j][i]
                int good = INT_MAX;
                for(int x = j; x <= i; x++) {
                    int cur = 0;
                    if(x - 1 >= j)
                        cur = max(cur, cache[j][x - 1]);
                    if(x + 1 <= i)
                        cur = max(cur, cache[x + 1][i]);
                    cur += x;
                    good = min(good, cur);
                }
                cache[j][i] = good;
            }
        }
        return  cache[1][n];
    }
};
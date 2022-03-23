// C++
// leetcode 879
// https://leetcode-cn.com/problems/profitable-schemes/
// 


class Solution {
public:
    int MOD = (int)1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& g, vector<int>& p) {
        int numOfProject = g.size();

        // f[i][j] 代表使用i个人利润达到j的方法有多少种
        int f[n + 1][minProfit + 1];
        memset(f, 0, sizeof(f));
        f[0][0] = 1;

        for(int i = 0; i < numOfProject; i++) {
            int numOfPeopleNeed = g[i];
            int profit = p[i];
            for(int j = n; j >= 0; j--) {
                for(int k = minProfit; k >= 0; k--) {
                    // 拿已经用j人赚了k钱的情况下，再做本次任务
                    int newPeople = j + numOfPeopleNeed;
                    if(newPeople > n)
                        continue;   // 人数超标，做不了
                    int newProfit = k + profit;
                    newProfit = min(newProfit, minProfit);  // 利润超了，算作minProfit
                    f[newPeople][newProfit] += f[j][k];
                    f[newPeople][newProfit] %= MOD;
                }
            } 
        }
        long res = 0;
        for(int i = 0; i <= n; i++) {
            res += f[i][minProfit];
            res %= MOD;
        }
        return  res;
    }
};
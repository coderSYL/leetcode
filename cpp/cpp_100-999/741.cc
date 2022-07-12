// C++
// leetcode 741
// https://leetcode.cn/problems/cherry-pickup/
// dp

class Solution {
public:
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size();
        int f[2 * n + 1][n + 1][n + 1];
        memset(f, -100, sizeof(f));
        f[2][1][1] = g[0][0];
        for (int k = 3; k <= 2 * n; k++) {
            for(int i1 = 1; i1 <= n; i1++) {
                for (int i2 = 1; i2 <= n; i2++) {
                    int j1 = k - i1, j2 = k - i2;
                    if (j1 <= 0 || j1 > n || j2 <= 0 || j2 > n)
                        continue;
                    int A = g[i1 - 1][j1 - 1], B = g[i2 - 1][j2 - 1];
                    if (A == -1 || B == -1)
                        continue;
                    int a = f[k - 1][i1 - 1][i2], b = f[k - 1][i1 - 1][i2 - 1], c = f[k - 1][i1][i2 - 1], d = f[k - 1][i1][i2];
                    int t = max(max(a,b), max(c,d)) + A;
                    if (i1 != i2)
                        t += B;
                    f[k][i1][i2] = t;
                }
            }
        }
        return f[2 * n][n][n] <= 0 ? 0 : f[2 * n][n][n];
    }
};
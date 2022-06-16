// C++
// leetcode 730
// https://leetcode.cn/problems/count-different-palindromic-subsequences/

class Solution {
public:
    int MOD = (int)1e9 + 7;
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        int f[n][n], L[4], R[4];
        memset(f, 0, sizeof(f));
        memset(L, -1, sizeof(L));
        for(int i = n-1; i >= 0; --i) {
            L[s[i] - 'a'] = i;
            memset(R, -1, sizeof(R));
            for(int j = i; j < n; j++) {
                R[s[j] - 'a'] = j;
                for (int k = 0; k < 4; ++k) {
                    if(L[k] == -1 || R[k] == -1)
                        continue;
                    int l = L[k], r = R[k];
                    if(l == r)
                        f[i][j] = (f[i][j] + 1) % MOD;
                    else if (l == -1)
                        f[i][j] = (f[i][j] + 2) % MOD;
                    else
                        f[i][j] = (f[i][j] + f[l+1][r-1] + 2) % MOD;
                }
            }
        }
        return f[0][n - 1];
    }
};
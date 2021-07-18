// C++
// leetcode 周赛 2021-07-18
// https://leetcode-cn.com/contest/weekly-contest-250/problems/maximum-number-of-points-with-cost/
// 第三题

typedef long long LL;

class Solution {
public:
    inline int abs(int a, int b) {
        return (a > b ? (a - b) : (b - a));
    }

    inline LL max_2(LL a, LL b) {
        return (a > b ? a : b);
    }

    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<LL>  res(n);
        vector<LL>  res_next(n);
        for(int i = 0; i < n; ++i) {
            res[i] = points[0][i];
        }

        for(int i = 1; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                LL temp = 0;
                for(int k = 0; k < n; ++k) {
                    temp = max_2(temp, res[k] - abs(j,k));
                }
                res_next[j] = points[i][j] + temp;
            }
            res.swap(res_next);
        }
        
        LL good = -10000;
        for(int i = 0; i < n; ++i) {
            good = max_2(good, res[i]);
        }
        return  good;
    }
};
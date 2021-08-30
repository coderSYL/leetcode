// C++
// leetcode 576
// https://leetcode-cn.com/problems/out-of-boundary-paths/
// 思路偷宫水三叶的，虽然步骤里没有没见过的，但还是感觉学到了

class Solution {
private:
    int m_;
    int n_;
    int maxMove_;
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int cache[51][51][51];
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        m_ = m;
        n_ = n;
        maxMove_ = maxMove;
        memset(cache, -1, sizeof(cache));
        return  dfs(startRow, startColumn, maxMove);
    }

    int dfs(int x, int y, int k) {
        if(x < 0 || x >= m_ || y < 0 || y >= n_)
            return  1;
        if(k == 0)
            return  0;
        if(cache[x][y][k] != -1)
            return  cache[x][y][k];
        int res = 0;
        for(auto d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            res += dfs(nx, ny, k-1);
            res %= 1000000007;
        }
        cache[x][y][k] = res;
        return  res;
    }
};
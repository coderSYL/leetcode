// C++
// leetcode 576
// https://leetcode-cn.com/problems/out-of-boundary-paths/
// 思路偷宫水三叶的，虽然步骤里没有没见过的，但还是感觉学到了

class Solution {
private:
    int MOD = (int)1e9 + 7;
    int m_, n_;   // 把边界记到类里，以便dfs
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};    // 4个方向
    int cache[51][51][51];  // 


public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        m_ = m;
        n_ = n;
        memset(cache, -1, sizeof(cache));   // 
        return  dfs(startRow, startColumn, maxMove);
    }


    int dfs(int x, int y, int k) {
        // 超出边界，返回一次
        if(x < 0 || x >= m_ || y < 0 || y >= n_)
            return  1;

        // 没超边界且剩余步数用尽，返回0
        if(k == 0)
            return  0;

        // 之前算过存下来了，直接返回
        if(cache[x][y][k] != -1)
            return  cache[x][y][k];

        // 没算过，这次算，然后存下来
        int res = 0;
        for(auto d : dirs) {
            // 计算方法为从4个方向往这走算少一步的和
            int nx = x + d[0], ny = y + d[1];
            res += dfs(nx, ny, k-1);
            res %= MOD;
        }
        cache[x][y][k] = res;

        return  res;
    }
};
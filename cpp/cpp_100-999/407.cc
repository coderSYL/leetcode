// C++
// leetcode 407
// https://leetcode-cn.com/problems/trapping-rain-water-ii/
// 思路偷三叶的，另外结构体偷另一个题解里的，把3元数写进结构体里，可以省空间和时间


class Solution {
public:
    struct Info // template
    {
        int x;
        int y;
        int h;
        Info(int x, int y, int h) : x(x), y(y), h(h) {}

        // 小顶堆的排序： 高度从小到大排列
        bool operator<(const Info& a) const
        {
            return h > a.h;
        }
    };
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<Info, vector<Info>> pq;
        bool vis[m][n];
        memset(vis, false, sizeof(vis));

        // 初始化，把周围一圈加进去
        for(int i = 0; i < n; i++) {
            pq.push(Info(0, i, heightMap[0][i]));
            pq.push(Info(m - 1, i, heightMap[m - 1][i]));
            vis[0][i] = true;
            vis[m - 1][i] = true;
        }
        for(int i = 1; i < m - 1; i++) {
            pq.push(Info(i, 0, heightMap[i][0]));
            pq.push(Info(i, n - 1, heightMap[i][n - 1]));
            vis[i][0] = true;
            vis[i][n - 1] = true;
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;

        while(!pq.empty()) {
            int x = pq.top().x, y = pq.top().y, h = pq.top().h;
            pq.pop();
            for(auto d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;
                if(vis[nx][ny])
                    continue;
                if(h > heightMap[nx][ny])
                    res += h - heightMap[nx][ny];
                pq.push(Info(nx, ny, max(h, heightMap[nx][ny])));
                vis[nx][ny] = true;
            }
        }

        return  res;

    }
};
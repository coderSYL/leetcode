// C++
// leetcode 847
// https://leetcode-cn.com/problems/shortest-path-visiting-all-nodes/
// 思路偷三叶的

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size();
        int possible = 1<<n;

        // 初始化所有的 (state, u) 距离为正无穷
        vector< vector<int> >   dist(possible, vector<int>(n, INT_MAX));

        // 将所有可能初始点入队
        queue< pair<int, int> > q;
        for(int i = 0; i < n; i++) {
            dist[1<<i][i] = 0;
            q.push( make_pair(1<<i, i));
        }

        // BFS
        while(!q.empty()) {
            int state = q.front().first;
            int u = q.front().second;
            int step = dist[state][u];
            q.pop();
            if(state == possible - 1)
                return  step;
            for(auto next : g[u]) {
                if(dist[state | (1<<next)][next] == INT_MAX) {
                    dist[state | (1<<next)][next] = step + 1;
                    q.push( make_pair(state | (1<<next), next) );
                }
            }
        }
        return  -1;
    }
};
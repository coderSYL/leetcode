// C++
// leetcode 787
// https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/
// 思路偷的三叶的，说是Bellman Ford算法，有时间的时候研究一下图路径算法
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;


        vector< vector<int> >   g(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++) {
            g[i][i] = 0;
        }
        for(auto x : flights) {
            g[x[0]][x[1]] = x[2];
        }


        for(int turn = 0; turn <= k; turn++) {
            vector<int> clone(dist);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[j] = (int)min((long)dist[j], (long)clone[i] + g[i][j]);
                }
            }
        }


        return  dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
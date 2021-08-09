// C++
// leetcode 802
// https://leetcode-cn.com/problems/find-eventual-safe-states/
// 

class Solution {
public:
    int N = 10010;
    int M = N * 4;
    int idx = 0;
    vector<int> he = vector<int>(N, -1);
    vector<int> e = vector<int>(M);
    vector<int> ne = vector<int>(M);
    vector<int> cnts = vector<int>(N, 0);

    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = he[a];
        he[a] = idx;
        idx++;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        // 存反向图，并统计入度
        for(int i = 0; i < n; i++) {
            for(auto j : g[i]) {
                add(j, i);
                cnts[i]++;
            }
        }
        // BFS 求反向图拓扑排序
        queue<int>  q;
        for(int i = 0; i < n; i++) {
            if(cnts[i] == 0)
                q.push(i);
        }

        while(!q.empty()) {
            int loop = q.front();
            q.pop();
            for(int i = he[loop]; i != -1; i = ne[i]) {
                int j = e[i];
                cnts[j]--;
                if(cnts[j] == 0)
                    q.push(j);
            }
        }

        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(cnts[i] == 0)
                res.push_back(i);
        }
        return  res;
    }
};
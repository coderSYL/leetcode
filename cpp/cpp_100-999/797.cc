// C++
// leetcode 797
// https://leetcode-cn.com/problems/all-paths-from-source-to-target/
// 自己做使用的bfs，然后看了三叶的dfs，发现确实表现好不少

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur{0};
    vector<vector<int>> g;
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        g = graph;
        dfs(0);
        return  res;
    }

    void dfs(int u) {
        if(u == n - 1) {
            res.push_back(cur);
            return;
        }
        for(auto next : g[u]) {
            cur.push_back(next);
            dfs(next);
            cur.pop_back();
        }
    }
};
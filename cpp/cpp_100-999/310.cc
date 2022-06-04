// C++
// leetcode 310
// https://leetcode-cn.com/problems/minimum-height-trees/

class Solution {
public:
    const static int N = 20010, M = 2 * N;
    int idx = 0;
    int he[N], e[M], ne[M];
    int f1[N], f2[N], g[N], p[N];
    
    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = he[a];
        he[a] = idx++;
    }

    int dfs1(int u, int fa) {
        for(int i = he[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if(j == fa)
                continue;
            int sub = dfs1(j, u) + 1;
            if(sub > f1[u]) {
                f2[u] = f1[u];
                f1[u] = sub;
                p[u] = j;
            } else if(sub > f2[u]) {
                f2[u] = sub;
            }
        }
        return f1[u];
    }

    void dfs2(int u, int fa) {
        for(int i = he[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if(j == fa)
                continue;
            if(p[u] != j)
                g[j] = max(g[j], f1[u] + 1);
            else
                g[j] = max(g[j], f2[u] + 1);
            g[j] = max(g[j], g[u] + 1);
            dfs2(j, u);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        memset(he, -1, sizeof(he));
        for(auto& p : edges) {
            int a = p[0], b = p[1];
            add(a, b);
            add(b, a);
        }
        dfs1(0, -1);
        dfs2(0, -1);
        vector<int> res;
        int min = n;
        for (int i = 0; i < n; i++) {
            int cur = max(f1[i], g[i]);
            if (cur < min) {
                min = cur;
                res.clear();
                res.push_back(i);
            } else if (cur == min) {
                res.push_back(i);
            }
        }
        return res;
    }
};
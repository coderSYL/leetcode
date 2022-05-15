// C++
// leetcode 913
// https://leetcode-cn.com/problems/cat-and-mouse/

class Solution {
public:
    int f[4 * 51][51][51];
    int n;
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        memset(f, -1, sizeof(f));
        return dfs(0, 1, 2, graph);
    }

    int dfs(int k, int a, int b, vector<vector<int>>& g) {
        if(k >= 4 * n) f[k][a][b] = 0;
        if (f[k][a][b] == -1) {
            if(a == 0) f[k][a][b] = 1;
            else if(a == b) f[k][a][b] = 2;
            else if(k % 2 == 0) {
                // mouse move
                bool win = false, draw = false;
                for(auto &ne : g[a]) {
                    int t = dfs(k+1, ne, b, g);
                    if(t == 1) win = true;
                    else if(t == 0) draw = true;
                    if(win) break;
                }
                if (win) f[k][a][b] = 1;
                else if (draw) f[k][a][b] = 0;
                else f[k][a][b] = 2;
            } else {
                // cat move
                bool win = false, draw = false;
                for(auto &ne : g[b]) {
                    if(ne == 0) continue;
                    int t = dfs(k+1, a, ne, g);
                    if(t == 2) win = true;
                    else if(t == 0) draw = true;
                    if(win) break;
                }
                if (win) f[k][a][b] = 2;
                else if (draw) f[k][a][b] = 0;
                else f[k][a][b] = 1;
            }
        }
        // cout<<k<<", "<<a<<", "<<b<<" : "<< f[k][a][b]<<endl;
        return f[k][a][b];
    }
};
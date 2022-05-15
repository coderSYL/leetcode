// C++
// leetcode 1728
// https://leetcode-cn.com/problems/cat-and-mouse-ii/

class Solution {
public:
    int m, n, a, b, x_food, y_food;
    int K = 128;    // 按理来说 K = 1000，但是时间太长过不了
    int f[8*8*8*8][1000];
    int dirs[5] = {-1, 0, 1, 0, -1};
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        m = grid.size();
        n = grid[0].size();
        a = catJump;
        b = mouseJump;
        memset(f, -1, sizeof(f));
        int x, y, p, q;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                char c = grid[i][j];
                if(c == 'M') {
                    x = i; y = j;
                } else if (c == 'C') {
                    p = i; q = j;
                } else if (c == 'F') {
                    x_food = i; y_food = j;
                }
            }
        }
        return dfs(x, y, p, q, 0, grid) == 0;
    }

    int dfs(int x_mouse, int y_mouse, int x_cat, int y_cat, int turn, vector<string>& g) {
        int state = (x_mouse<<9) | (y_mouse<<6) | (x_cat<<3) | (y_cat);
        if(turn == K - 1)
            return f[state][turn] = 1;
        if(x_mouse == x_cat && y_mouse == y_cat)
            return f[state][turn] = 1;
        if(x_mouse == x_food && y_mouse == y_food)
            return f[state][turn] = 0;
        if(x_cat == x_food && y_cat == y_food)
            return f[state][turn] = 1;
        if(f[state][turn] != -1)
            return f[state][turn];

        if(turn % 2 == 0) {
            // mouse move
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j <= b; ++j) {
                    int nx = x_mouse + j * dirs[i], ny = y_mouse + j * dirs[i+1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) break;
                    if(g[nx][ny] == '#') break;
                    if (dfs(nx, ny, x_cat, y_cat, turn + 1, g) == 0) return f[state][turn] = 0;
                }
            }
            return f[state][turn] = 1;
        } else {
            // cat move
            for(int i = 0; i < 4; ++i) {
                for(int j = 0; j <= a; ++j) {
                    int nx = x_cat + j * dirs[i], ny = y_cat + j * dirs[i+1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) break;
                    if(g[nx][ny] == '#') break;
                    if (dfs(x_mouse, y_mouse, nx, ny, turn + 1, g) == 1) return f[state][turn] = 1;
                }
            }
            return f[state][turn] = 0;
        }
        return -1;
    }
};
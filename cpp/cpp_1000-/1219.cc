// C++
// leetcode 1219
// https://leetcode-cn.com/problems/path-with-maximum-gold/solution/

class Solution {
public:
	int m, n;
	int dirs[5] = {-1, 0, 1, 0, -1};
    int getMaximumGold(vector<vector<int>>& grid) {
    	m = grid.size(), n = grid[0].size();
    	vector<vector<bool>> vis(m, vector<bool>(n, false));
    	int res = 0;
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			if(grid[i][j] != 0) {
    				vis[i][j] = true;
                    res = max(res, dfs(i, j, grid, vis));
                    vis[i][j] = false;
    			}
    		}
    	}
        return res;
    }

    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>> &vis) {
    	int res = grid[x][y];
    	for(int i = 0; i < 4; i++) {
    		int nx = dirs[i] + x, ny = y + dirs[i + 1];
    		if(nx < 0 || ny <0 || nx >= m || ny >= n) continue;
    		if(grid[nx][ny] == 0) continue;
    		if(vis[nx][ny]) continue;
    		vis[nx][ny] = true;
    		res = max(res, grid[x][y] + dfs(nx, ny, grid, vis));
    		vis[nx][ny] = false;
    	}
    	return res;
    }
};
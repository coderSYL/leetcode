// C++
// leetcode 200
// https://leetcode-cn.com/problems/number-of-islands/

class Solution {
public:
	int m, n;
	int dirs[5] = {-1, 0, 1, 0, -1};
	int dfs(vector<vector<char>>& grid, int x, int y) {
		if(x < 0 || y < 0 || x >= m || y >= n) return 0;
		if(grid[x][y] == '0') return 0;
		grid[x][y] = '0';
		for(int i = 0; i < 4; ++i) {
			int nx = x + dirs[i];
			int ny = y + dirs[i + 1];
			dfs(grid, nx, ny);
		}
		return 1;
	}

    int numIslands(vector<vector<char>>& grid) {
    	m = grid.size();
    	n = grid[0].size();
    	int res = 0;
    	for(int i = 0; i < m; ++i) {
    		for(int j = 0; j < n; ++j) {
    			res += dfs(grid, i, j);
    		}
    	}
    	return res;
    }
};
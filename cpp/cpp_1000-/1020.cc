// C++
// leetcode 1020
// https://leetcode-cn.com/problems/number-of-enclaves/

class Solution {
public:
	int m, n;
	int dirs[5] = {-1, 0, 1, 0, -1};

	void removeDfs(vector<vector<int>>& grid, int x, int y) {
		if(grid[x][y] == 0) return;
		grid[x][y] = 0;
		for(int i = 0; i < 4; i++) {
			int nx = x + dirs[i], ny = y + dirs[i+1];
			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			removeDfs(grid, nx, ny);
		}
		return;
	}

    int numEnclaves(vector<vector<int>>& grid) {
    	m = grid.size(), n = grid[0].size();
    	for(int i = 0; i < n; i++) {
    		removeDfs(grid, 0, i);
    		removeDfs(grid, m-1, i);
    	}
    	for(int i = 1; i < m; i++) {
    		removeDfs(grid, i, 0);
    		removeDfs(grid, i, n-1);
    	}
    	int res = 0;
    	for(int i = 1; i < m-1; i++) {
    		for(int j = 1; j < n-1; j++) {
    			if(grid[i][j] == 1) res++;
    		}
    	}
    	return res;
    }
};
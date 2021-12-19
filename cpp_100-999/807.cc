// C++
// leetcode 807
// https://leetcode-cn.com/problems/max-increase-to-keep-city-skyline/
// 模拟

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int row[n], col[n];
    	memset(row, 0, sizeof(row));
    	memset(col, 0, sizeof(col));
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			int h = grid[i][j];
    			row[i] = max(row[i], h);
    			col[j] = max(col[j], h);
    		}
    	}
    	int res = 0;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			res += min(row[i], col[j]) - grid[i][j];
    		}
    	}
    	return res;
    }
};
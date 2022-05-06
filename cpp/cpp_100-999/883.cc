// C++
// leetcode 883
// https://leetcode-cn.com/problems/projection-area-of-3d-shapes/

class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int x[n], y[n];
    	int res = 0;
    	memset(x, 0, sizeof(x));
    	memset(y, 0, sizeof(y));
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			int v = grid[i][j];
    			if(v > 0)
    				res++;
    			x[i] = max(x[i], v);
    			y[j] = max(y[j], v);
    		}
    	}
    	for(int i = 0; i < n; i++) {
    		res += x[i];
    		res += y[i];
    	}
    	return res;
    }
};
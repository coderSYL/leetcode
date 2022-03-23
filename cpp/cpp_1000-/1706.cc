// C++
// leetcode 1706
// https://leetcode-cn.com/problems/where-will-the-ball-fall/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
    	int n = grid[0].size();
    	int m = grid.size();
    	vector<int> res(n);
    	for(int i = 0; i < n; i++) {
    		int x = i;
    		int y = 0;
    		while(y < m) {
    			int displacement = grid[y][x];
    			int nx = x + displacement;
    			if(nx < 0 || nx >= n) break;
    			if(grid[y][nx] != displacement) break;
    			x = nx;
    			y++;
    		}
    		if(y != m) res[i] = -1;
    		else res[i] = x;
    	}
    	return res;
    }
};
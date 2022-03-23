// C++
// leetcode 1034
// https://leetcode-cn.com/problems/coloring-a-border/
#include<vector>
class Solution {
public:
	int dirs[5] = {-1, 0, 1, 0, -1};
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    	int goodColor = grid[row][col], m = grid.size(), n = grid[0].size();
    	if(goodColor == color)	return grid;
    	queue<int>	q;	// 需要保证 q 中都是好的
    	set<int>	visited;	// 在 q 中都算访问过
    	vector<int>	willBeChanged;
    	q.push(row * 55 + col);
    	visited.insert(row * 55 + col);

    	while(!q.empty()) {
    		int idx = q.front(), x = idx / 55, y = idx % 55, cnt = 0;
    		q.pop();
    		for(int i = 0; i < 4; i++) {
    			int nx = x + dirs[i], ny = y + dirs[i + 1];
    			// 超越边界
    			if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
    			// 颜色不对
    			if(grid[nx][ny] != goodColor) continue;
    			// 符合，周边多了一个 goodColor
    			else cnt++;	
    			// 没入过队
    			if(visited.find(nx * 55 + ny) == visited.end()) {
    				q.push(nx * 55 + ny);
    				visited.insert(nx * 55 + ny);
    			}
    		}
    		if(cnt != 4) willBeChanged.push_back(idx);
    	}
    	for(auto x : willBeChanged)
    		grid[x/55][x%55] = color;
    	return grid;
    }
};
// C++
// leetcode 417
// https://leetcode-cn.com/problems/pacific-atlantic-water-flow/

class Solution {
public:
    int n;
	int getIdx(int x, int y) {
		return x * n + y;
	}

	int dirs[5] = {-1, 0, 1, 0, -1};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    	int m = heights.size();
        n = heights[0].size();
    	// set<int> toPacific; // 左上方向
    	// set<int> toAtlantic; // 右下方向
    	bool toPacific[m][n];
    	bool toAtlantic[m][n];
    	memset(toPacific, 0, sizeof(toPacific));
    	memset(toAtlantic, 0, sizeof(toAtlantic));

    	queue<int> q;
    	// 找出左上的，先进行初始化，左上方向的每一个都行
    	for(int i = 0; i < n; i++) {
    		q.push(getIdx(0, i));
    		toPacific[0][i] = true;
    	}
    	for(int i = 1; i < m; i++) {
    		q.push(getIdx(i, 0));
    		toPacific[i][0] = true;
    	}
    	// 开始work
    	while(!q.empty()) {
    		int idx = q.front();
    		q.pop();
    		int x = idx/n, y = idx%n;
    		for(int i = 0; i < 4; i++) {
    			int nx = x + dirs[i], ny = y + dirs[i+1];
    			if(nx < 0 || ny < 0 || nx >= m || ny >= n)
    				continue;
    			if(heights[nx][ny] >= heights[x][y] && !toPacific[nx][ny]) {
    				toPacific[nx][ny] = true;
    				q.push(getIdx(nx, ny));
    			}
    		}
    	}

    	// 找出右下的，先进行初始化，左上方向的每一个都行
    	for(int i = 0; i < n; i++) {
    		q.push(getIdx(m-1, i));
    		toAtlantic[m-1][i] = true;
    	}
    	for(int i = 0; i < m-1; i++) {
    		q.push(getIdx(i, n-1));
    		toAtlantic[i][n-1] = true;
    	}
    	// 开始work
    	while(!q.empty()) {
    		int idx = q.front();
    		q.pop();
    		int x = idx/n, y = idx%n;
    		for(int i = 0; i < 4; i++) {
    			int nx = x + dirs[i], ny = y + dirs[i+1];
    			if(nx < 0 || ny < 0 || nx >= m || ny >= n)
    				continue;
    			if(heights[nx][ny] >= heights[x][y] && !toAtlantic[nx][ny]) {
    				toAtlantic[nx][ny] = true;
    				q.push(getIdx(nx, ny));
    			}
    		}
    	}

    	vector<vector<int>> res;
    	// 开始填充答案
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			if(toPacific[i][j] && toAtlantic[i][j])
    				res.push_back(vector<int>{i,j});
    		}
    	}
    	return res;
    }
};
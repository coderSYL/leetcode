// C++
// leetcode 675
// https://leetcode.cn/problems/cut-off-trees-for-golf-event/

class Solution {
public:
	int m, n;
	int dirs[5] = {-1, 0, 1, 0, -1};

	// 与forest同样尺寸，供bfs使用
	vector<vector<bool>> vis;
	void reset() {
		for(auto &l : vis){
			for(int i = 0; i < n; ++i)
				l[i] = false;
		}
	}

	struct info
	{
		int x, y, height;
		info() {}
		info(int x_, int y_, int h_) : x(x_), y(y_), height(h_) {}
		// 为使默认pq能让height小的在前面
		bool operator<(const info &a) const{
			return height > a.height;
		}
	};

	// 计算从cur到next所需最小步数，不能到达则返回-1
	int bfs(vector<vector<int>>& f, int cur, int next) {
        if(cur == next)
            return 0;
		queue<int> qu;
		reset();
		qu.push(cur);
		int step = 0;
		vis[cur/n][cur%n] = true;
		while(!qu.empty()) {
			step++;
			int size = qu.size();
			while(size--) {
				cur = qu.front();
				qu.pop();
				int x = cur / n, y = cur % n;
				for(int i = 0; i < 4; i++) {
					int nx = x + dirs[i], ny = y + dirs[i+1];
					if(nx<0 || ny<0 || nx>=m || ny>=n || vis[nx][ny])
						continue;
					vis[nx][ny] = true;
					int idx = nx * n + ny;
					if(f[nx][ny] == 0)
						continue;
					if(idx == next)
						return step;
					qu.push(idx);
				}
			}
		}
		return -1;
	}

    int cutOffTree(vector<vector<int>>& forest) {
    	// 预处理得到所有需要去的点
    	priority_queue<info> q;
    	m = forest.size(); n = forest[0].size();
    	vis.resize(m, vector<bool>(n));
    	for(int i = 0; i < m; ++i) {
    		for(int j = 0; j < n; ++j) {
    			if(forest[i][j] > 1) {
    				q.push(info(i, j, forest[i][j]));
    			}
    		}
    	}
    	// (x, y)代表当前坐标，每次从q中取出下一步需要达到的位置，计算所需步数
    	int x = 0, y = 0, res = 0;
    	while(!q.empty()) {
    		int nx = q.top().x, ny = q.top().y;
            // cout<<q.top().height<<endl;
            q.pop();
    		int step = bfs(forest, x*n+y, nx*n+ny);
    		if(step == -1)
    			return -1;
    		res += step;
    		x = nx; y = ny;
    	}
    	return res;
    }
};
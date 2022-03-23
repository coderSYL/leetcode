// C++
// leetcode 419
// https://leetcode-cn.com/problems/battleships-in-a-board/

// 找到每个战舰的左上角才计数
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'X') {
                    if(i != 0 && board[i-1][j] == 'X') continue;
                    if(j != 0 && board[i][j-1] == 'X') continue;
                    res++;
                }
            }
        }
        return res;
    }
};

// // 方法二，bfs
// class Solution {
// public:
//     int countBattleships(vector<vector<char>>& board) {
//         vector<int> d{1, 0, -1, 0, 1};
//     	int m = board.size(), n = board[0].size();
//     	queue<int> q;
//     	function<int(int,int)> bfs = [&](int x, int y) -> int {
//     		if(board[x][y] == '.') return 0;
//     		q.push(x * n + y);
//     		while(!q.empty()) {
//     			int idx = q.front();
//     			q.pop();
//     			int x0 = idx / n, y0 = idx % n;
//     			board[x0][y0] = '.';
//     			for(int i = 0; i < 4; i++) {
//     				int nx = x0 + d[i];
//     				int ny = y0 + d[i + 1];
//     				if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
//     				if(board[nx][ny] == '.') continue;
//     				q.push(nx * n + ny);
//     			}
//     		}
//     		return 1;
//     	};
//     	int res = 0;
//     	for(int i = 0; i < m; i++) {
//     		for(int j = 0; j < n; j++) {
//     			res += bfs(i, j);
//     		}
//     	}
//     	return res;
//     }
// };


// // 方法二，dfs
// class Solution {
// public:
//     int countBattleships(vector<vector<char>>& board) {
//         vector<int> d{1, 0, -1, 0, 1};
//         int m = board.size(), n = board[0].size();
//         queue<int> q;
//         function<int(int,int)> dfs = [&](int x, int y) -> int {
//             if(x < 0 || y < 0 || x >= m || y >= n) return 0;
//             if(board[x][y] == '.') return 0;
//             board[x][y] = '.';
//             for(int i = 0; i < 4; i++) {
//                 int nx = x + d[i];
//                 int ny = y + d[i + 1];
//                 dfs(nx, ny);
//             }
//             return 1;
//         };
//         int res = 0;
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 res += dfs(i, j);
//             }
//         }
//         return res;
//     }
// };
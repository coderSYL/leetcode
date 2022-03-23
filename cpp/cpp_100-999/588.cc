// C++
// leetcode 588
// https://leetcode-cn.com/problems/knight-probability-in-chessboard/
// 滚动二维数组动态规划

class Solution {
public:
	int dirs[8][2] = {{2, 1}, {2, -1}, { -2, 1}, { -2, -1}, {1, 2}, {1, -2}, { -1, 2}, { -1, -2}};
	double knightProbability(int n, int k, int row, int col) {
		int kk = k;
		double base = 1.0 / pow(8.0, kk % 10);
		kk -= kk % 10;
		while(kk) {
			kk -= 10;
			base /= 1073741824.0;
		}
		double f[2][n][n];
		memset(f, 0, sizeof(f));
		f[0][row][col] = base;
		for (int i = 1; i <= k; i++) {
			int u = i % 2;
			memset(f[u], 0, sizeof(f[u]));
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					double more = f[1 - u][x][y];
					for (int j = 0; j < 8; j++) {
						int nx = x + dirs[j][0];
						int ny = y + dirs[j][1];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						f[u][nx][ny] += more;
					}
				}
			}
		}
		double res = 0;
		int last = k % 2;
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				res += f[last][x][y];
			}
		}
		return res;
	}
};
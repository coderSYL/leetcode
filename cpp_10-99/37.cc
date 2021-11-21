// C++
// leetcode 37
// https://leetcode-cn.com/problems/sudoku-solver/

class Solution {
public:
	// 用来存坐标对
	struct bi {
		int a, b;
		bi(int a, int b) : a(a) , b(b) {}
	};
	// row col square 分别对应 9行 9列 9个块
	// row[i] 代表第 i 行的数据填充情况，如果 a 存在，那么row[i]的第 a 位是1，否则是0
	// square 分块方法，从左到右，从上到下，前三行012，以此类推
	int row[9];
	int col[9];
	int square[9];
	// 指示是否找到正确的数独答案
	bool done_;
	// 用来记录需要填充数字的坐标对
	vector<bi>	blank;
	// 根据坐标对 (a , b) 得到块号
	int getIdx(int a, int b) {return	(a / 3) * 3 + b / 3;}
	// 根据 board 初始化 row col 与square
	// 将需要填空的地方记录到 blank 中
	// 将 done_ 标记为false
	void setAll(vector<vector<char>>& board) {
		done_ = false;
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(square, 0, sizeof(square));
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(board[i][j] == '.') {
					blank.push_back(bi(i, j));
					continue;
				}
				int u = 1 << (board[i][j] - '0');
				row[i] |= u;
				col[j] |= u;
				square[getIdx(i, j)] |= u;
			}
		}
	}

	void dfs(int idx, vector<vector<char>>& board) {
		// 深搜结束，将 done_ 标记为 true
		if(idx == blank.size()) {
			done_ = true;
			return;
		}
		// 获取本次dfs的行号、列号、块号
		int i = blank[idx].a, j = blank[idx].b, k = getIdx(i, j);
		// 获取本次dfs取数的可能性
		int possible = row[i] | col[j] | square[k];
		for(int u = 1; u < 10; u++) {
			// 如果已经找到了，直接结束
			if(done_)	return;
			// 若 possible 的第 u 位是 1，则表明填u会相斥，跳过
			if(((possible >> u) & 1) == 1)	continue;
			// 填写
			board[i][j] = '0' + u;
			// 把三个状态量改一下
			row[i] |= 1 << u;
			col[j] |= 1 << u;
			square[k] |= 1 << u;
			dfs(idx + 1, board);
			// 结束后把状态量改回来
			row[i] &= ~(1 << u);
			col[j] &= ~(1 << u);
			square[k] &= ~(1 << u);
		}
	}

    void solveSudoku(vector<vector<char>>& board) {
    	setAll(board);
    	dfs(0, board);
    }
};
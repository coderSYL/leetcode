// C++
// leetcode 51
// https://leetcode-cn.com/problems/n-queens/
// dfs + 回溯 + 位运算

class Solution {
public:
	vector<int>	cur;	// cur[i] 表示第 i 行的 'Q' 的信息
	int cur_idx, full;
	vector<string> standard;
	vector<vector<string>> res;

	int log2(int x) {
		int res = 0;
		if(x >= 65535) {res += 16; x >>= 16;}
		if(x >= 256) {res += 8; x >>= 8; }
		if(x >= 16) { res += 4; x >>= 4; }
		while(x != 1) { x >>= 1; res++; }
		return	res;
	}

	void putInRes() {
		vector<string> onePossible;
		for(int i = 0; i < cur_idx; i++) {
			int idx = log2(cur[i]);
			onePossible.push_back(standard[idx]);
		}
		res.push_back(onePossible);
	}

	void dfs(int row, int ld, int rd) {
		if(row == full) {
			putInRes();
			return;
		}
		int goodPos = full & ~(row | ld | rd);
		while(goodPos) {
			int p = goodPos & -goodPos;
			goodPos -= p;
			cur[cur_idx++] = p;
			dfs(row + p, (ld + p) << 1, (rd + p) >> 1);
			cur_idx--;
		}
	}

    vector<vector<string>> solveNQueens(int n) {
    	vector<char>	tmp(n, '.');
    	for(int i = 0; i < n; i++) {
    		tmp[i] = 'Q';
    		standard.push_back(string(tmp.begin(), tmp.end()));
    		tmp[i] = '.';
    	}
    	cur_idx = 0;
    	cur.resize(n);
    	full = (1 << n) - 1;
    	dfs(0, 0, 0);
    	return	res;
    }
};
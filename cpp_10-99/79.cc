// C++
// leetcode 79
// https://leetcode-cn.com/problems/word-search/

class Solution {
public:

	string word_;
	int m_, n_;
	int d[5] = {-1, 0, 1, 0 , -1};
	bool dfs(vector<vector<char>>& board, int x, int y, int idx) {
		if(idx == word_.size())
			return	true;
		if(x < 0 || x >= m_ || y < 0 || y >= n_)
			return	false;
		char c = board[x][y];
		if(c == '.' || c != word_[idx])
			return	false;

		board[x][y] = '.';
		for(int i = 0; i < 4; i++) {
			int nx = x + d[i];
			int ny = y + d[i + 1];
			if(dfs(board, nx, ny, idx + 1))
				return	true;
		}
		board[x][y] = c;
		return false;
	}

    bool exist(vector<vector<char>>& board, string word) {
    	word_ = word;
    	m_ = board.size();
    	n_ = board[0].size();
    	for(int i = 0; i < m_; i++) {
    		for(int j = 0;  j < n_; j++) {
    			if(dfs(board, i, j, 0))
    				return	true;
    		}
    	}
    	return	false;
    }
};
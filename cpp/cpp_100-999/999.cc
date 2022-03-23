// C++
// leetcode 999
// https://leetcode-cn.com/problems/available-captures-for-rook/

class Solution {
public:
	int dirs[5] = {-1, 0, 1, 0, -1};

	// 如果坐标(a, b)在棋盘内，则返回true，否则返回false
	bool isValid(int a, int b) {
		if(a < 0 || b < 0 || a >7 || b > 7)
			return false;
		return true;
	}

    int numRookCaptures(vector<vector<char>>& board) {
    	int x = 0, y = 0;
    	while(board[x][y] != 'R') {
    		y++;
    		if(y == 8) {
    			x++;
    			y = 0;
    		}
    	}
    	int res = 0;
    	for(int i = 0; i < 4; i++) {
    		int nx = x + dirs[i];
    		int ny = y + dirs[i+1];
    		while(isValid(nx, ny) && board[nx][ny] == '.') {
    			nx += dirs[i];
    			ny += dirs[i+1];
    		}
    		if(isValid(nx, ny) && board[nx][ny] == 'p')
    			res++;
    	}
    	return res;
    }
};
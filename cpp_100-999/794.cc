// C++
// leetcode 794
// https://leetcode-cn.com/problems/valid-tic-tac-toe-state/
// 略繁琐的一道题，考虑清楚各种情况

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
    	char X = 'X', O = 'O';
    	// 两个计数器，统计 'O' 与 'X'
    	int cntO = 0, cntX = 0;
    	for(auto line : board) {
    		for(auto c : line) {
    			if(c == 'O')
    				cntO++;
    			else if(c == 'X')
    				cntX++;
    		}
    	}
    	// 数量不合格
    	if(cntO != cntX && (cntO + 1 != cntX)) return false;
    	// 如果哪一方胜利，则置为 true
    	bool winX = false, winO = false;
    	// 行判断
    	for(auto line : board) {
    		if(line == "OOO")
    			winO = true;
    		else if(line == "XXX")
    			winX = true;
    	}
    	// 列判断
    	for(int i = 0; i < 3; i++) {
    		if(board[0][i] == X && board[1][i] == X && board[2][i] == X)
    			winX = true;
    		else if(board[0][i] == O && board[1][i] == O && board[2][i] == O)
    			winO = true;
    	}
    	// 如果 X 还没获胜，进行对角线判断
    	if(!winX) {
	    	if(board[0][0] == X && board[1][1] == X && board[2][2] == X)
	    		winX = true;
	    	else if(board[0][2] == X && board[1][1] == X && board[2][0] == X)
	    		winX = true;
    	}
    	// 如果 O 还没获胜，进行对角线判断
    	if(!winO) {
	    	if(board[0][0] == O && board[1][1] == O && board[2][2] == O)
	    		winO = true;
	    	else if(board[0][2] == O && board[1][1] == O && board[2][0] == O)
	    		winO = true;
    	}
    	// 不存在两方都胜利的情况
    	if(winX && winO) return false;
    	// 若 X 胜利，则 X 的数量必定大于 O
    	if(winX && (cntX == cntO)) return false;
    	// 若 O 胜利，则 O 的数量必定等于 X
    	if(winO && (cntX > cntO)) return false;

    	return true;
    }
};
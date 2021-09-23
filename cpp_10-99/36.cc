// C++
// leetcode 36
// https://leetcode-cn.com/problems/valid-sudoku/
// 思路:
// 主要就判断三种
// 横着的，这个可以用9bit判断
// 竖着的，这个要用81bit判断
// 方块的，这个要用81bit来判断

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board){
    	bool check[9][9];
    	bool oneLineCheck[9];
    	bool square[3][3][9];
    	memset(check, 0, sizeof(check));
    	memset(oneLineCheck, 0, sizeof(oneLineCheck));
    	memset(square, 0, sizeof(square));
    	int temp = 0;	// good value : [0, 8]
    	int heng = 3;	// good value : 0, 1, 2
    	int shu = 3;	// good value : 0, 1, 2
    	for(int i = 0; i < 9; i++)	// 开始，每轮处理一行
    	{
    		memset(oneLineCheck, 0, sizeof(oneLineCheck));
    		vector<char> &a = board[i];
    		for(int j = 0; j < 9; j++)    // 内循环，每轮处理一行中的一个
    		{
    			temp = (int)a[j] - 49;
    			heng = i / 3;
    			shu = j / 3;
    			if(temp >= 0)
    			{
    				// 竖check
    				if(check[j][temp])	return false;
    				else	check[j][temp] = true;
    				// 横check
    				if(oneLineCheck[temp])	return false;
    				else	oneLineCheck[temp] = true;
    				// 方块check
    				if(square[heng][shu][temp])	return false;
    				else	square[heng][shu][temp] = true;
    			}
    		}
    	}
    	return true;
    }
};
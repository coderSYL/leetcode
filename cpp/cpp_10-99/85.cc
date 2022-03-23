// C++
// leetcode 85
// https://leetcode-cn.com/problems/maximal-rectangle/
// 另外整一个尺寸差不多的int二维数组，用来记录每个位置距离左侧最近0的距离
// 多一行，值全为0，用来方便单调栈的使用，具体意义见84题
// 处理完数据后，对每一列使用单调栈，具体流程见题解84


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	int row = matrix.size();
    	if(row == 0)	return	0;
    	int col = matrix[0].size();
    	if(col == 0)	return	0;

    	// info[i][j]表示此位置左侧距离最近的 0 的距离
    	vector<vector<int>> info(row + 1, vector<int>(col, 0));

    	for(int i = 0; i < row; i++) {
    		// 第一个
    		if(matrix[i][0] == '1')
    			info[i][0] = 1;
    		// 后面的都是
    		for(int j = 1; j < col; j++) {
    			info[i][j] = (matrix[i][j] == '1' ? info[i][j - 1] + 1 : 0);
            }
            
    	}

    	int res = 0;
    	for(int j = 0; j < col; j++) {
            stack<int> stk;
    		for(int i = 0; i <= row; i++) {
    			while(!stk.empty() && info[stk.top()][j] > info[i][j]) {
    				int tmp = stk.top();
    				stk.pop();
    				res = max(res, info[tmp][j] * (stk.empty() ? i : i - stk.top() - 1));
    			}
    			stk.push(i);
    		}
    	}
    	return	res;
    }
};
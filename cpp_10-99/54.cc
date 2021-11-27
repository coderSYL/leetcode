// C++
// leetcode 54
// https://leetcode-cn.com/problems/spiral-matrix/

class Solution {
public:
	vector<int>	res;
	int idx;
	void recursion(vector<vector<int>>& matrix, int up, int down, int left, int right) {
		if(idx == res.size())	return;
		// 从左到右
		for(int i = left; i <= right; i++)
			res[idx++] = matrix[up][i];
		// 从上到下
		for(int i = up + 1; i <= down; i++)
			res[idx++] = matrix[i][right];
		// 若最后一轮只有一行或者一列，此处需结束
        if(idx == res.size())	return;
        // 从右到左
		for(int i = right - 1; i >= left; i--)
			res[idx++] = matrix[down][i];
		// 从下到上
		for(int i = down - 1; i > up; i--)
			res[idx++] = matrix[i][left];
		recursion(matrix, up + 1, down - 1, left + 1, right - 1);
	}

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	res.resize(matrix.size() * matrix[0].size());
    	idx = 0;
    	recursion(matrix, 0, matrix.size() - 1, 0 ,matrix[0].size() - 1);
    	return res;
    }
};
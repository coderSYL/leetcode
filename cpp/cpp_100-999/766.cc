// C++
// leetcode 766
// https://leetcode-cn.com/problems/toeplitz-matrix/
// 每行每行判断，相邻两行，除去行1第1个元素和行2最后一个元素，其余元素一一对应

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    	int m = matrix.size();
    	int n = matrix[0].size();

    	for(int i = 0; i < m - 1; ++i) {
    		for(int j = 0; j < n - 1; ++ j) {
    			if( matrix[i][j] != matrix[i+1][j+1])
    				return false;
    		}
    	}

    	return true;
    }
};
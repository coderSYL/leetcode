// C++
// leetcode 566
// https://leetcode-cn.com/problems/reshape-the-matrix/
// 简简单单的赋值

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    	int l = mat[0].size();
    	int n = mat.size() * l;
    	if(n != r * c)
    		return mat;
    	vector<vector<int>> res(r, vector<int>(c));
    	for(int i = 0; i < n; ++i) {
    		res[i / c][i % c] = mat[i / l][i % l];
    	}
    	return res;
    }
};
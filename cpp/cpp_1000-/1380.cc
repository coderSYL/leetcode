// C++
// leetcode 1380
// https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/
// 找每行的最小数，每列的最大数
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    	int m = matrix.size(), n = matrix[0].size();
    	vector<int> minInLine(m, INT_MAX);
    	vector<int> maxInCol(n, 0);
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			minInLine[i] = min(minInLine[i], matrix[i][j]);
    			maxInCol[j] = max(maxInCol[j], matrix[i][j]);
    		}
    	}
    	vector<int> res;
    	set<int> tmp(minInLine.begin(), minInLine.end());
    	for(auto & x : maxInCol) {
    		if(tmp.find(x) != tmp.end())
    			res.push_back(x);
    	}
    	return res;
    }
};
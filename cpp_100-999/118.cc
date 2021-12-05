// C++
// leetcode 118
// https://leetcode-cn.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> res;
    	for(int level = 1; level <= numRows; level++) {
    		vector<int>	tmp(level, 1);
    		for(int i = 1; i < level - 1; i++) {
    			tmp[i] = res.back()[i] + res.back()[i - 1];
    		}
    		res.push_back(tmp);
    	}
    	return	res;
    }
};
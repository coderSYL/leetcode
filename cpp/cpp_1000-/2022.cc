// C++
// leetcode 2022
// https://leetcode-cn.com/problems/convert-1d-array-into-2d-array/

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    	if(m * n != original.size())
    		return vector<vector<int>>{};
    	vector<vector<int>> res(m, vector<int>(n));
    	int i = 0, j = 0;
    	for(auto & x : original) {
    		res[i][j] = x;
    		++j;
    		if(j == n) {
    			j = 0;
    			++i;
    		}
            
    	}
    	return res;
    }
};
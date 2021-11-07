// C++
// leetcode 74
// https://leetcode-cn.com/problems/search-a-2d-matrix/
// 二分


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int m = matrix.size(), n = matrix[0].size();
    	if(target < matrix[0][0] || target > matrix[m - 1][n - 1])
    		return	false;
    	int l = 0, r = m * n - 1;
    	while(l <= r) {
    		int mid = (l + r) / 2;
    		int u = matrix[mid / n][mid % n];
    		if(u > target)
    			r = mid - 1;
    		else if(u < target)
    			l = mid + 1;
    		else
    			return true;
    	}
    	return	false;
    }
};
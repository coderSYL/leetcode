// C++
// leetcode 1252
// https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
    	vector<int> row(m, 0);
    	vector<int> col(n, 0);
    	for(auto &p : indices) {
    		row[p[0]]++;
    		col[p[1]]++;
    	}
    	int res = 0, tmp = 0;
    	for(int i = 0; i < m; i++) {
    		tmp = row[i];
    		for (int j = 0; j < n; j++) {
    			res += (tmp + col[j]) & 1;
    		}
    	}
    	return res;
    }
};
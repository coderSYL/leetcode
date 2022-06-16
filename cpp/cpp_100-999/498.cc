// C++
// leetcode 498
// https://leetcode.cn/problems/diagonal-traverse/

class Solution {
public:
	int d[2] = {-1, 1};

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    	int m = mat.size(), n = mat[0].size(), bound = m + n - 2;
    	vector<int> res(m * n);
    	int idx = 0;
    	int cur_sum = 0;
    	int p = 0;
    	while(cur_sum <= bound) {
    		int x = cur_sum * (1-p), y = cur_sum * p;
    		if(x >= m) {
    			y = x - m + 1;
    			x = m-1;
    		}
    		if(y >= n) {
    			x = y - n + 1;
    			y = n - 1;
    		}
    		while(x >= 0 && x < m && y >= 0 && y < n) {
    			res[idx++] = mat[x][y];
    			x += d[p];
    			y += d[1-p];
    		}
    		p = 1-p;
    		cur_sum++;
    	}
    	return res;

    }
};
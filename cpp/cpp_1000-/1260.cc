// C++
// leetcode 1260
// https://leetcode.cn/problems/shift-2d-grid/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
    	int n = g[0].size(), m = g.size(), mn = m * n;
    	k %= mn;

    	// 不用移动
        if (k == 0)
            return g;

        // 长度为 k 的
        int arr[k];
    	int in_cnt = 0, out_cnt = 0, tmp = 0;
    	int i = 0, j = 0, p = 0;
    	while(p < k) {
    		arr[p++] = g[i][j];
    		j++;
    		if (j == n) {
    			i++;
    			j = 0;
    		}
    	}

    	p = 0;
    	while(out_cnt++ <= mn) {
    		tmp = g[i][j];
    		g[i][j] = arr[p];
    		arr[p] = tmp;
    		p = (p + 1) % k;
    		if (++j == n) {
    			i++;
    			j = 0;
    		}
    		i %= m;
    	}
    	return g;
    }
};
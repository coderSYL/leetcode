// C++
// leetcode 1582
// https://leetcode.cn/problems/special-positions-in-a-binary-matrix/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
    	int m = mat.size(), n = mat[0].size();
    	vector<bool> occupied(n, false);
    	int res = 0;
    	for (int i = 0; i < m; i++) {
    		// 统计此行 1 的个数
    		int cnt = 0, last = -1;
    		for (int j = 0; j < n; j++) {
    			if (mat[i][j] == 1) {
    				cnt++;
    				last = j;
    			}
    		}

    		// 无 1，过
    		if (cnt == 0)
    			continue;

    		// 很多 1，给有 1 的列标记，过
    		if (cnt > 1) {
    			for (int j = 0; j < n; j++) {
    				if (mat[i][j] == 1) {
    					occupied[j] = true;
    				}
    			}
    			continue;
    		}

    		// 1 个 1
    		// 之前此列出现过 1，过
    		if (occupied[last])
    			continue;
            
            // 看看之后此列有无 1
    		for (int j = i + 1; j < m; j++) {
    			if (mat[j][last] == 1) {
    				occupied[last] = true;
    			}
    		}
    		if (occupied[last]) {
    			continue;
    		} else {
    			res++;
    			occupied[last] = true;
    		}
    	}

    	return res;
    }
};
// C++
// leetcode 661
// https://leetcode-cn.com/problems/image-smoother/

class Solution {
public:
	int m, n;
	bool isValid(int x, int y) {
		if(x < 0 || y < 0 || x >= m || y >= n)
			return false;
		return true;
	}

	int getAve(vector<vector<int>>& img, int x, int y) {
		int res = 0, cnt = 0;
		for(int i = -1; i <= 1; i++) {
			for(int j = -1; j <= 1; j++) {
				if(isValid(x + i, y + j)) {
					cnt++;
					res += img[x+i][y+j];
				}
			}
		}
		return res / cnt;
	}
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    	m = img.size(), n = img[0].size();
    	vector<vector<int>> res(m, vector<int>(n));
    	for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
    			res[i][j] = getAve(img, i, j);
    		}
    	}
    	return res;
    }
};
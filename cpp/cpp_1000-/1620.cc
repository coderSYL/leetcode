// C++
// leetcode 1620
// https://leetcode.cn/problems/coordinate-with-maximum-network-quality/

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    	int g[110][110];
    	int x = 0, y = 0, val = 0, r2 = radius * radius;
    	memset(g, 0, sizeof(g));
    	for (auto & t : towers) {
    		int a = t[0], b = t[1], q = t[2];
    		for (int i = max(0, a - radius); i <= a + radius; i++) {
    			for (int j = max(0, b - radius); j <= b + radius; j++) {
    				int d2 = (a - i) * (a - i) + (b - j) * (b - j);
	    			if (d2 > r2)
	    				continue;
	    			g[i][j] += floor(q / ( 1 + sqrt(d2)));
	    			if (g[i][j] > val) {
	    				x = i;
	    				y = j;
	    				val = g[i][j];
	    			} else if (g[i][j] == val && (i < x || (i == x && j < y))) {
	    				x = i;
	    				y = j;
	    			}
    			}
    		}
    	}
    	return vector<int>{x, y};
    }
};
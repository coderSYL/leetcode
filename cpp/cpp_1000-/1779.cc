// C++
// leetcode 1779
// https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution {
public:
	int getD(int x1, int y1, int x2, int y2) {
		return (x1 > x2 ? x1 - x2: x2 - x1) + (y1 > y2 ? y1 - y2: y2 - y1);
	}

    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    	int cur = INT_MAX, res = -1;
    	for (int i = 0; i < points.size(); i++) {
            int x2 = points[i][0], y2 = points[i][1];
            if (x2 != x && y2 != y)
            	continue;
    		int d = getD(x, y, x2, y2);
    		if (d < cur) {
    			cur = d;
    			res = i;
    		}
    		if (cur == 0) {
    			return res;
    		}
    	}
    	return res;
    }
};
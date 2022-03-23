// C++
// leetcode 1610
// https://leetcode-cn.com/problems/maximum-number-of-visible-points/

const double PI = 3.1415926535;
const double eps = 1e-8;
#include <math.h>	// atan2
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
    	int n = points.size(), Ox = location[0], Oy = location[1];
    	double an[2 * n];
    	int same = 0, idx = 0;
    	for(auto& point : points) {
    		int dx = point[0] - Ox;
    		int dy = point[1] - Oy;
    		if(dx == 0 && dy == 0) {
    			same++;
    			continue;
    		}
    		double a = atan2(dy, dx) * 180 / PI;
    		an[idx++] = a;
    		if(a < angle + eps) an[idx++] = a + 360;
    	}
    	sort(an, an + idx);
    	int res = 0;
    	int l = 0, r = 0;
    	while(r < idx) {
    		while(r < idx && an[r] - an[l] <= angle + eps) {
    			r++;
    		}
    		res = max(res, r - l);
    		l++;
    	}
    	return res + same;
    }
};
// C++
// leetcode 1037
// https://leetcode.cn/problems/valid-boomerang/

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
    	int a1 = points[0][0], a2 = points[0][1];
    	int b1 = points[1][0], b2 = points[1][1];
    	int c1 = points[2][0], c2 = points[2][1];
    	if((b2-a2) * (c1-a1) == (c2-a2) * (b1-a1))
    		return false;
    	return true;
    }
};
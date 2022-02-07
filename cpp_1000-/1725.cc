// C++
// leetcode 1725
// https://leetcode-cn.com/problems/number-of-rectangles-that-can-form-the-largest-square/

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
    	int big = 0, num = 0;
    	for(auto & re : rectangles) {
    		int len = min(re[0], re[1]);
    		if(len < big) continue;
    		else if(len == big) {
    			num++;
    		} else {
    			big = len;
    			num = 1;
    		}
    	}
    	return num;
    }
};
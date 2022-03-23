// C++
// leetcode 747
// https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    	int max = -1, max2 = -1;
    	int res = -1;
    	bool moreThanOnce = false;
    	for(int i = 0; i < nums.size(); ++i) {
    		int x = nums[i];
    		if(max == -1) {
    			// 没录入
    			max = x;
    			res = i;
    			moreThanOnce = false;
    		} else if(x > max2) {
    			if(x == max) {
    				moreThanOnce = true;
    			} else {
    				max2 = x;
    			}
    			if(max2 > max) {
    				swap(max, max2);
    				moreThanOnce = false;
    				res = i;
    			}
    		}
    	}
    	if(moreThanOnce) return -1;
    	if(max2 * 2 > max) return -1;
    	return res;
    }
};
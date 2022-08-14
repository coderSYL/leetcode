// C++
// leetcode 485
// https://leetcode.cn/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    	int cur = 0, res = 0;
    	for (auto x : nums) {
    		if (x == 1) {
    			res = max(res, ++cur);
    		} else {
    			cur = 0;
    		}
    	}
    	return res;
    }
};
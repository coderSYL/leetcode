// C++
// leetcode 1413
// https://leetcode.cn/problems/minimum-value-to-get-positive-step-by-step-sum/

class Solution {
public:
    int minStartValue(vector<int>& nums) {
    	int res = INT_MAX, cur = 0;
    	for (auto x : nums) {
    		cur += x;
    		res = min(res, cur);
    	}
    	if (res > 0)
    		res = 1;
    	else
    		res = 1 - res;
    	return res;
    }
};
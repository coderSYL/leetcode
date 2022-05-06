// C++
// leetcode 396
// https://leetcode-cn.com/problems/rotate-function/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    	int n = nums.size();
    	int sum = 0, res = 0;
    	for(int i = 0; i < n; i++) {
    		res += i * nums[i];
    		sum += nums[i];
    	}
    	int cur = res;
    	for(int i = n-1; i >=0; i--) {
    		cur = cur + sum - n * nums[i];
    		res = max(res, cur);
    	}
    	return res;
    }
};
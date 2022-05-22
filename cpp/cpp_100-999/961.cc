// C++
// leetcode 961
// https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    	int pre[3];
    	pre[0] = -1;
    	pre[1] = -1;
    	pre[2] = -1;
    	int n = nums.size();
    	for(int i = 0; i < n; i++) {
    		int x = nums[i];
    		if(x == pre[0] || x == pre[1] || x == pre[2])
    			return x;
    		pre[i%3] = x;
    	}
    	return -1;
    }
};
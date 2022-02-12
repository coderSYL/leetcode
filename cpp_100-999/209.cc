// C++
// leetcode 209
// https://leetcode-cn.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    	int left = 0, right = 0, sum = nums[0], n = nums.size();
   		int res = INT_MAX;
    	while(right < n) {
    		while(target > sum) {
    			right++;
    			if(right < n) {
    				sum += nums[right];
    			} else {
    				break;
    			}
    		}
    		if(target <= sum) {
    			res = min(res, right - left + 1);
    			sum -= nums[left];
                left++;
    		}
    	}
    	return res == INT_MAX ? 0 : res;
    }
};
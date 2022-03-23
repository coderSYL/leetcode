// C++
// leetcode offer 53 - I
// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
// 

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int n = nums.size();
        if(n == 0)  return 0;
    	int l = 0;
    	int r = n - 1;
    	while(l < r) {
    		// 找左边
    		int mid = l + (r - l) / 2;
    		if(nums[mid] >= target) {
    			r = mid;
    		} else {
    			l = mid + 1;
    		}
    	}
    	if(nums[l] != target)
    		return	0;
    	int left = l;
    	l = 0;
    	r = n - 1;
    	while(l < r) {
    		// 找右边
    		int mid = l + (r - l + 1) / 2;
    		if(nums[mid] > target) {
    			r = mid -1;
    		} else {
    			l = mid;
    		}
    	}
    	if(nums[r] != target)
    		return	0;
    	return r - left + 1;
    }
};
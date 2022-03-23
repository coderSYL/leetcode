// C++
// leetcode 704
// https://leetcode-cn.com/problems/binary-search/
// 二分

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int n = nums.size();
    	int l = 0, r = n - 1;
    	while(l <= r) {
    		int mid = (l + r) / 2;
    		int val_mid = nums[mid];
    		if(val_mid == target) {
    			return	mid;
    		} else if(val_mid > target) {
    			r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	return	-1;
    }
};
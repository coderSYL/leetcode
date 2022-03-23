// C++
// leetcode 540
// https://leetcode-cn.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	int n = nums.size();
    	int l = 0, r = nums.size() - 1;
    	while(l < r) {
    		int mid = (l + r) / 2;
    		if(mid % 2 == 0) mid++;
    		if(nums[mid] == nums[mid - 1]) {
    			// 左边ok，把范围缩至左边
    			l = mid + 1;
    		} else if (nums[mid] == nums[mid + 1]){
    			// 右边ok，把范围缩至右边
    			r = mid - 1;
    		} else {
    			return nums[mid];
    		}
    	}
    	return nums[l];
    }
};
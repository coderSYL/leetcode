// C++
// leetcode 35
// https://leetcode-cn.com/problems/search-insert-position/
// 思路:
// 二分法，稍微改了一下，mid 不用+1 -1 了，这样判定条件就要放宽一点
// left == right 或者 left + 1 == right都要进行最终审判

class Solution {
public:
	int bisearch(vector<int>& nums, int left, int right, int target){
		while(left <= right)
		{
			if(left +1 >= right)
			{
				if(target == nums[left])	return left;
				return left + 1;
			}
			int mid = left + (right - left) / 2;
			if(target == nums[mid])	return mid;
			else if(target < nums[mid]) right = mid;
			else left = mid;
		}
		return -1;	// -1 means errors
	}

    int searchInsert(vector<int>& nums, int target) {
    	int size = nums.size();
    	if(size ==  0)	return 0;	// empty vector
    	if(target < nums[0])	return 0;	// smaller than every int in nums
    	if(target > nums[size-1])	return size;	// bigger than every int in nums
    	return bisearch(nums, 0, size - 1, target);
    }
};
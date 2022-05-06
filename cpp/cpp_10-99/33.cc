// C++
// leetcode 33
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
// 思路:
// 经典二分法
// 不同之处是第一层的二分要做多一点判断

class Solution {
public:
	int bisearch(vector<int>& nums, int low, int high, int target){
		while(low <= high)
		{
			int mid = low + (high - low) / 2;
			if(nums[mid] == target)	return mid;
			else if(nums[mid] < target)	low = mid + 1;
			else	high = mid - 1;
		}
		return -1;
	}

	int inside(vector<int>& nums, int l, int r, int target){
		if(l > r)	return -1;
		int mid = l + (r - l) / 2;
		if(target == nums[mid])	return mid;
		if(target <= nums[r] && target > nums[mid])
			return bisearch(nums, mid + 1, r, target);
		if(target >= nums[l] && target < nums[mid])	
			return bisearch(nums, l, mid - 1, target);
		if(nums[mid] < nums[l])
			return inside(nums, l, mid - 1, target);
		else
			return inside(nums, mid + 1, r, target);
	}

    int search(vector<int>& nums, int target) {
    	return inside(nums, 0, nums.size() - 1, target);
    }
};
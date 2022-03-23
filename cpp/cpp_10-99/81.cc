// C++
// leetcode 81
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
	bool binarySearch(vector<int>& nums, int l, int r, int t) {
		while(l <= r) {
			int mid = (l + r) / 2;
			if(nums[mid] == t)
				return	true;
			else if(nums[mid] > t) {
				r = mid - 1;	
			} else 
				l = mid + 1;
		}
		return	false;
	}

	bool searchII(vector<int>& nums, int l, int r, int t) {
		if(l > r || l < 0 || r < 0 || l >= nums.size() || r >= nums.size())
			return	false;
		if(l + 1 >= r) {
			if(nums[l] == t || nums[r] == t)
				return	true;
		}

		int mid = (l + r) / 2;
		if(nums[mid] == t)
			return	true;

		if(nums[mid] < nums[l]) {
			// 左边 II，右边binary
			if(searchII(nums, l, mid - 1, t))
				return	true;
			return	binarySearch(nums, mid + 1, r, t);
		} else if(nums[mid] > nums[l]) {
			// 左边 binary，右边 II
			if(binarySearch(nums, l, mid - 1, t))
				return	true;
			return	searchII(nums, mid + 1, r, t);
		} else {
			// 分情况讨论
			if(nums[mid] > nums[r]) {
				// 右边 II
				return	searchII(nums, mid + 1, r, t);
			} else if(nums[mid] < nums[r]) {
				// 左边II，右边binary
				if(searchII(nums, l, mid - 1, t))
					return	true;
				return	binarySearch(nums, mid + 1, r, t);
			} else {
				// 无法分别，都带入II
				if(searchII(nums, l, mid - 1, t))
					return	true;
				return	searchII(nums, mid + 1, r, t);
			}
		}
		return	false;	// never
	}
	
    bool search(vector<int>& nums, int target) {
    	return searchII(nums, 0, nums.size() - 1, target);
    }
};
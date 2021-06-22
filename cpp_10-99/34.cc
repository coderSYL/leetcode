// C++
// leetcode 34
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 思路:
// 先用二分法找到其中一个值为target的index，然后再往前和往后遍历找到不为target的index

class Solution {
public:
	int bisearch(vector<int>& nums, int l, int r, int target){
		int mid;
		while(l<=r)
		{
			mid = l + (r - l) / 2;
			if(target == nums[mid])	return mid;
			else if(target < nums[mid])	r = mid - 1;
			else 	l = mid + 1;
		}
		return -1;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
    	int size = nums.size();
    	int start = bisearch(nums, 0, size - 1, target);
    	if(start == -1)	return vector<int>{-1,-1};
    	int end = start;
    	while(start >=0 && nums[start] == target)	start--;
    	while(end<size && nums[end] == target)	end++;
    	return vector<int>{start + 1, end - 1};
    }
};
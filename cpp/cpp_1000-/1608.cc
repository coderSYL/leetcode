// C++
// leetcode 1608
// https://leetcode.cn/problems/special-array-with-x-elements-greater-than-or-equal-x/

class Solution {
public:
    int specialArray(vector<int>& nums) {
		// 排序
    	sort(nums.begin(), nums.end());
    	int n = nums.size();

		// 如果最小的数大于 n，则特征数为 n
    	if (nums[0] >= n)
    		return n;
		
		// 找特征数
    	for (int x = 1; x < n; x++) {
    		if (nums[n-x] >= x && nums[n-x-1] < x)
    			return x;
    	}
    	return -1;
    }
};
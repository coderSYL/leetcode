// C++
// leetcode 137
// https://leetcode-cn.com/problems/single-number-ii/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int size = nums.size(), i;
    	for(i = 0; i < size; i = i + 3){
    		if(i==size-1 || nums[i] !=nums[i+1])
    			break;
    	}
    	return nums[i];
    }
};
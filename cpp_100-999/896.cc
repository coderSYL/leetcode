// C++
// leetcode 896
// https://leetcode-cn.com/problems/monotonic-array/
// 用两个bool记录是否出现过增或者减
// 既增过也减过就false
// 否则true

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
    	int nMinus1 = nums.size() - 1;
    	bool up = false;
 		bool down = false;
    	for(int i = 0; i < nMinus1; ++i) {
    		if(nums[i] < nums[i+1])
    			up = true;
    		else if(nums[i] > nums[i+1])
    			down = true;
    		if(up && down)
    			return	false;
    	}
    	return	true;
    }
};
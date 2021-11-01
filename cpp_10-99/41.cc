// C++
// leetcode 41
// https://leetcode-cn.com/problems/first-missing-positive/
// 


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int res = 1;
    	for(int x : nums) {
    		if(x < res)
    			continue;
    		else if(x == res)
    			res++;
    		else
    			return	res;
    	}
    	return	res;
    }
};
// C++
// leetcode 665
// https://leetcode-cn.com/problems/non-decreasing-array/
// 思路
// 逐个检查
// 如果有下降的，看是不是第一次
// 如果是第一次看能不能修复，
// 第一次且能修复则继续，否则返回false

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
    	int size = nums.size();
    	bool haveChance = true;
    	for(int i = 1; i < size; i++)
    	{
    		if(nums[i] < nums[i - 1])
    		{
    			if(haveChance)
    			{
    				haveChance = false;
    				int after = INT_MAX;
    				int before = INT_MIN;
    				if(i > 1)	before = nums[i-2];
    				if(i + 1 < size)	after = nums[i+1];
    				if(before  <= nums[i] || after>=nums[i -1])	continue;
    				return false;
    			}
    			else	return false;
    		}
    	}
    	return true;
    }
};
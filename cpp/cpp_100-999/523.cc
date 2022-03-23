/*
 * C++
 * leetcode 523
 * url: https://leetcode-cn.com/problems/continuous-subarray-sum/
 * 先计算前缀和与unordered_map
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	int size = nums.size(), prefixSumTemp = 0, ret = 0;
    	unordered_map<int,int> judge;
    	judge[0] = 0;

    	for(int i =1; i<=size; i++){
    		prefixSumTemp = (prefixSumTemp+nums[i-1])%k;
    		if(judge.find(prefixSumTemp) != judge.end()){	// exist
    			if(i-judge[prefixSumTemp]>=2)
    				return true;
    		}
    		else	// not exist, fill it in
    			judge[prefixSumTemp] = i;
    	}
    	return false;
	}
};
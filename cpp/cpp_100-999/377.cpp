/*
 * C++
 * leetcode377
 * url:https://leetcode-cn.com/problems/combination-sum-iv/
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	long long dp[target+1];
    	int size = nums.size();
    	dp[0] = 1;

    	for(int i =1; i<=target; i++)
    		dp[i] = 0;

    	for(int i = 1; i<=target; i++){
    		for(auto x:nums){
    			if(i>=x){
    				dp[i]= dp[i]+dp[i-x];
    				dp[i]%=INT_MAX;
    			}
    			else
    				break;
    		}
    	}
    	return dp[target];
    }
};
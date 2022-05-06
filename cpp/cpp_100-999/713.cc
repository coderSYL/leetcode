// C++
// leetcode 713
// https://leetcode-cn.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    	int cur = 1, n = nums.size();
    	int res = 0;
    	for(int i = 0, j = 0; i < n; i++) {
            j = max(i, j);
    		while(j < n && cur * nums[j] < k) {
    			cur *= nums[j];
    			j++;
    		}
    		
    		res += j-i;
    		// cout<<i<<" : "<<res<<endl;
    		if(cur != 1) {
    			cur /= nums[i];
    		}
    	}
    	return res;
    }
};
// C++
// leetcode 413
// https://leetcode-cn.com/problems/arithmetic-slices/
// 顺着就做出来了

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
    	int n = nums.size();
    	if(n <= 2)
    		return	0;
    	int i = 0;
    	int j = 1;
    	int dif = nums[j] - nums[i];
    	int res = 0;
    	while(true) {
    		while(j != n && nums[j] - nums[j - 1] == dif){
    			j++;
    		}
    		int m = j - i - 1;
    		res += m * (m - 1) / 2;
    		i = j - 1;
            if(j == n)
            	return	res;
    		dif = nums[j] - nums[i];
    	}
    	return	-1;	// never
    }
};
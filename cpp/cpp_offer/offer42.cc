// C++
// leetcode offer 42
// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
// 简简单单一个dp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int	n = nums.size();
    	int sum = 0;
    	int m = 0;
    	int res = nums[0];
    	for(int i = 0; i < n; ++i) {
            int temp = nums[i];
            sum += temp;
    		res = max(res, sum - m);
    		m = min(m, sum);
    	}
    	return	res;
    }
};	
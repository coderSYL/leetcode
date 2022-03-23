// C++
// leetcode 1838
// https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/
// 滑动窗口

typedef	long long LL;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
    	int n = nums.size();
    	if(n < 2)
    		return	n;
    	sort(nums.begin(), nums.end());
    	int res = 0;
    	LL tempSum = 0;
    	for(int i = 0, j = 0; j < n; ++j) {
    		while((long)(nums[j]) * (j - i) - tempSum > k) {
    			// 以num[j]为基准来算频数，超过k操作数就移动左边界
    			tempSum -= nums[i];
    			++i;
    		}
    		tempSum += nums[j];
    		res = max(res, j - i + 1);
    	}
    	
    	return	res;
    }
};
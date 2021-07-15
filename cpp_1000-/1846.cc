// C++
// leetcode 1846
// https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/
// 排序，然后遍历每个元素是否能为结果贡献 1

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    	sort(arr.begin(), arr.end());
        int n = arr.size();
    	int res = 0;
    	for(int i = 0; i < n; ++i) {
    		res = min(res + 1, arr[i]);
    	}
    	return	res;
    }
};
// C++
// leetcode 1619
// https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/

class Solution {
public:
    double trimMean(vector<int>& arr) {
    	sort(arr.begin(), arr.end());
    	int n = arr.size(), total = 0;
    	for (int i = n / 20; i < n - n /20; i++)
    		total += arr[i];
    	return 1.0 * total / (0.9 * n);
    }
};
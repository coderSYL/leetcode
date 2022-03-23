// C++
// leetcode 1218
// https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/
// 


class Solution {
public:
	int f[40010] = {0};	// f[20005]	代表0结尾的最长
	int res = 0;
	int _diff;
	void put(int a) {
		f[a + 20005] = max(f[a + 20005], f[a + 20005 - _diff] + 1);
		res = max(res, f[a + 20005]);
	}

    int longestSubsequence(vector<int>& arr, int difference) {
		_diff = difference;
    	for(auto x : arr)
    		put(x);
    	return	res;
    }
};
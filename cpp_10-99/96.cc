// C++
// leetcode 96
// https://leetcode-cn.com/problems/unique-binary-search-trees/
// 方法一：dfs + 记忆化
// 方法二：dp

class Solution {
public:
    map<int, int>   f;

	int dfs(int l, int r) {
		if(f.find(r - l) != f.end())	return	f[r - l];
		if(l > r)	return 1;
		int res = 0;
		for(int i = l; i <= r; i++) {
			int left = dfs(l, i - 1), right = dfs(i + 1, r);
			res += left * right;
		}
		f[r - l] = res;
		return	res;
	}

    int numTrees(int n) {
    	return	dfs(1, n);
    }
};

// // dp
// class Solution {
// public:
//     int numTrees(int n) {
//     	int dp[n + 1];
//     	memset(dp, 0, sizeof(dp));
//     	dp[0] = 1;
//     	dp[1] = 1;
//     	for(int i = 2; i <= n; i++) {
//     		for(int j = 0; j < i; j++)
//     			dp[i] += dp[j] * dp[i - j - 1];
//     	}
//     	return	dp[n];
//     }
// };
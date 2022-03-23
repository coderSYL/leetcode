// C++
// leetcode 1994
// https://leetcode-cn.com/problems/the-number-of-good-subsets/
// 数据范围是30，小于30的质数有2,3,5,7,11,13,17,19,23,29
class Solution {
public:
	int MOD = (long)1e9 + 7;
	int prime[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int full = (1 << 10);

	// 此函数可以得到int x的特征数
	// 若x为1，或者x的因子中有多个重复的某质数
	// 例如 12 = 2 * 2 * 3，因子中有两个指数2
	// 以上两种情况返回 INT_MAX
	// 否则按照prime[10]的表来推断返回值
	// 例如 77 = 7 * 11，7、11的index分别为4、5
	// 0000110000000000... 为返回值
	// 0123456
	int getIdx(int x) {
		if (x == 1) return INT_MAX;
		int y = 0;
		for (int i = 0; i < 10; i++) {
			if (x % prime[i] == 0) {
				x /= prime[i];
				y |= (1 << i);
			}
		}
		if (x > 1) return INT_MAX;
		return y;
	}

	int numberOfGoodSubsets(vector<int>& nums) {
		// 初始化cnt 并统计nums中各数字出现次数
		int cnt[31];	// 
		memset(cnt, 0, sizeof(cnt));
		for (auto & x : nums) {
			cnt[x]++;
		}
		
		long f[1024];
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for (int i = 2; i <= 30; i++) {
			if (cnt[i] == 0) continue;
			int cur = getIdx(i);
			if (cur == INT_MAX) continue;
			for (int prev = full - 1; prev >= 0; prev--) {
				if ((prev & cur) != 0) continue;
				f[prev | cur] += f[prev] * cnt[i];
				f[prev | cur] %= MOD;
			}
		}
		long res = 0;
		for (int i = 1; i < full; i++) {
			res = (res + f[i]) % MOD;
		}
		while (cnt[1]--) {
			res *= 2;
			res %= MOD;
		}
		return (int)res;
	}
};
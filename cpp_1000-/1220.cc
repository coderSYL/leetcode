// C++
// leetcode 1220
// https://leetcode-cn.com/problems/count-vowels-permutation/

class Solution {
public:
	int MOD = (int)1e9 + 7;
    int countVowelPermutation(int n) {
    	int f[2][5]; // f[i][j]表示长度为i的，结尾为{a,e,i,o,u}的可能性
    	for(int i = 0; i < 5; ++i) f[1][i] = 1;
    	for(int i = 2; i <= n; i++) {
    		// 计算长度i的可能
    		int u = i % 2;
    		int pre = 1 - u;
    		f[u][0] = ((f[pre][1] + f[pre][2]) % MOD  + f[pre][4]) % MOD;
    		f[u][1] = (f[pre][0] + f[pre][2]) % MOD;
    		f[u][2] = (f[pre][1] + f[pre][3]) % MOD;
    		f[u][3] = f[pre][2];
    		f[u][4] = (f[pre][2] + f[pre][3]) % MOD;
    	}
    	int res = 0;
    	for(int i = 0; i < 5; ++i) {
    		res += f[n%2][i];
    		res %= MOD;
    	}
    	return res % MOD;
    }
};
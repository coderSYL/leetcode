// C++
// leetcode 629
// https://leetcode-cn.com/problems/k-inverse-pairs-array/

class Solution {
public:
	int MOD = (int)1e9 + 7;
    int kInversePairs(int n, int k) {
    	int f[k + 1];	// f[i]代表当前的i个逆序对有多少个
    	memset(f, 0, sizeof(f));

    	// 设初始值，针对n = 1时候
    	f[0] = 1;
    	for(int i = 2; i <= n; i++) {
    		// 有i种选择，所以f_new[i] = sum(f[j])  j范围 (j - i, j]
    		int sum = 0;
    		for(int j = k; j > k - i; j--) {
    			if(j < 0)
    				break;
    			sum += f[j];
    			sum %= MOD;
    		}

    		for(int j = k; j > 0; j--) {
    			int tmp = f[j];
    			f[j] = sum;
    			sum -= tmp;
    			if(j - i >= 0)
    				sum += f[j - i];
    			sum = (sum % MOD + MOD) % MOD;
    		}
    	}
    	return	f[k];
    }
};
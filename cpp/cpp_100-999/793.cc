// C++
// leetcode 793
// https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/
// 经典二分

class Solution {
public:
	// 计算 (5 * x)! 的结尾有多少个 0
	long get55(long x) {
		long res = 0;
		while(x > 0) {
			res += x;
			x /= 5;
		}
		return res;
	}

    int preimageSizeFZF(int k) {
    	int l = 0, r = k;
    	while(l <= r) {
    		long mid = (r - l) / 2 + l;
    		long x = get55(mid);
    		if (x == k)
    			return 5;
    		else if (x > k)
    			r = mid - 1;
    		else
    			l = mid + 1;
    	}
    	return 0;
    }
};
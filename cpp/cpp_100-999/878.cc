// C++
// leetcode 878
// https://leetcode.cn/problems/nth-magical-number/

class Solution {
public:
	long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	long lcm(long a, long b) {
		return a * b / gcd(a, b);
	}

    int nthMagicalNumber(int n_, int a_, int b_) {
    	long a = a_, b = b_, c = lcm(a_, b_), n = n_;
        // cout<<c<<endl;
    	long l = 0, r = LONG_MAX;
    	while(l < r) {
    		long mid = (l + r) >> 1;
    		if (mid / a + mid / b - mid / c >= n)
    			r = mid;
    		else
    			l = mid + 1;
    	}
    	return (int) (r % 1000000007);
    }
};
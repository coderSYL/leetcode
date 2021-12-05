// C++
// leetcode 372
// https://leetcode-cn.com/problems/super-pow/

class Solution {
public:
	int pow10AfterMod1337(int a) {
		int c = (a * a) % 1337;
		a = c;	// ^2
		c = (c * c) % 1337;
		c = (c * c) % 1337;
		return (a * c) % 1337;
	}

    int superPow(int a, vector<int>& b) {
    	int base = a % 1337;
    	int res = 1;
    	for(int i = b.size() - 1; i >= 0; --i) {
    		int u = b[i];
    		int nextBase = pow10AfterMod1337(base);
    		while(u != 0) {
    			if((u & 1) == 1) {
    				res = (res * base) % 1337;
    			}
    			u >>= 1;
    			base = (base * base) % 1337;
    		}
    		base = nextBase;
    	}
    	return res;
    }
};
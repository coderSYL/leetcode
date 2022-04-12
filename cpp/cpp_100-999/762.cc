// C++
// leetcode 762
// https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
public:
	int isPrime[20] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};

	int countOne(int a) {
		int num = 0;
		while(a > 0) {
			if(a & 1)
				num++;
			a >>= 1;
		}
		return num;
	}

    int countPrimeSetBits(int left, int right) {
    	int res = 0;
    	for(int i = left; i <= right; i++) {
    		res += isPrime[countOne(i)];
    	}
    	return res;
    }
};
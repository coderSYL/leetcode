// C++
// leetcode 204
// https://leetcode-cn.com/problems/count-primes/

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        int res = 0;
    	for(int i = 2; i < n; i++) {
    		if(isPrime[i]) {
                for(int j = 2 * i; j< n; j += i) {
                    isPrime[j] = false;
                }
                res++;
            }
    	}
        return res;
    }
};
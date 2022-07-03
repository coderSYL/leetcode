// C++
// leetcode 1175
// https://leetcode.cn/problems/prime-arrangements/

class Solution {
public:
	long MOD = (int)1e9 + 7;
    int numPrimeArrangements(int n) {
    	long primeCnt = 1;
    	for (int i = 3; i <= n; i += 2) {
    		if(isPrime(i))
    			primeCnt++;
    	}

    	long notPrime = n - primeCnt;
    	long res = 1;
    	// cout<<"prime : "<<primeCnt<<" not : "<<notPrime<<endl;
    	while(notPrime > 1) {
    		res *= notPrime--;
    		res %= MOD;
    	}
    	while(primeCnt > 1) {
    		res *= primeCnt--;
    		res %= MOD;
    	}
    	return (int)res;
    }

    bool isPrime(int n) {
    	if (n == 1)
    		return false;
    	int l = 0, r = n, mid = 0;
    	if(r > 46340)
    		r = 46340;

    	while(l <= r) {
    		mid = (l + r) >> 1;
    		if(mid * mid == n) {
    			return false;
    		} else if (mid * mid < n) {
    			l = mid + 1;
    		} else {
    			r = mid - 1;
    		}
    	}
    	// cout<<n<<" l : "<<l<<" r : "<<r<<endl;
    	for(long i = 2; i < l; i++) {
    		if(n % i == 0)
    			return false;
    	}
    	return true;
    }
};
// C++
// leetcode 313
// https://leetcode-cn.com/problems/super-ugly-number/
// 这应该算dp?

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> uglyNum(n + 1);
        uglyNum[1] = 1;
        vector<int> pp(m, 1);
        int before = 1;
        for(int i = 2; i <= n; i++) {
            int ith = INT_MAX;
            for(int j = 0; j < m; j++) {
                int base = primes[j];
                while(uglyNum[pp[j]] * base <= before)
                    pp[j]++;
                ith = min(uglyNum[pp[j]] * base, ith);
            }
            uglyNum[i] = ith;
            before = ith;
        }
        return  uglyNum[n];
    }
};
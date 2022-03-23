// C++
// leetcode offer 10 I
// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
// 

class Solution {
public:
    int fib(int n) {
        if(n < 2)
            return  n;
        int MOD = (int)1e9 + 7;
        int a = 0;
        int b = 1;
        int idx = 1;  // b的index；
        while(idx < n) {
            a = (a + b) % MOD;
            swap(a,b);
            idx++;
        }
        return  b;
    }
};
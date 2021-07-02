// C++
// leetcode 50
// https://leetcode-cn.com/problems/powx-n/
// 递归

class Solution {
public:
    double myPow(double x, int n) {
        // 直接结束
        if(n == 0)
            return 1.0;
        // 归归
        if(n % 2 == 0)
            return myPow(x * x, n/2);
        // 直接结束
        if(n == 1)
            return x;
        if(n == -1)
            return 1 / x;
        // 归归
        n--;
        return myPow(x * x, n / 2) * x;
    }
};
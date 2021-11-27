// C++
// leetcode 172
// https://leetcode-cn.com/problems/factorial-trailing-zeroes/
// 这道题可以等价成，求 [1, n] 中因子 2 与 5 的最小值
// 因为 2 的个数肯定多于 5 的个数
// 所以该题也等价于求因子 5 的个数

class Solution {
public:
    int trailingZeroes(int n) {
        int base = 5, res = 0;
        while(base <= n) {
            res += n / base;
            base *= 5;
        }
        return  res;
    }
};
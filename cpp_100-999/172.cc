// C++
// leetcode 172
// https://leetcode-cn.com/problems/factorial-trailing-zeroes/
// 这道题可等价于求因子 5 的个数

class Solution {
public:
    int trailingZeroes(int n) {
        int  res = 0;
        while(n >= 5) {
            n /= 5;
            res += n;
        }
        return  res;
    }
};
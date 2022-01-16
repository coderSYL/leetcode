// C++
// leetcode 1716
// https://leetcode-cn.com/problems/calculate-money-in-leetcode-bank/
// 每周的和是一个等差数列，首项为28，公差为7

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int left = n % 7;
        int res = (28 + 21 + week * 7) * week / 2 + left * week;
        res += (1 + left) * left / 2;
        return res;
    }
};
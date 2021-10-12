// C++
// leetcode 29
// https://leetcode-cn.com/problems/divide-two-integers/
// 思路:
// 转化为long再做计算，如果结果不在范围内，返回INT_MAX

class Solution {
public:
    int divide(int dividend, int divisor) {
        long l_above = (long) dividend;
        long l_belowed = (long) divisor;
        long long_ret = l_above / l_belowed;

        if(long_ret < INT_MAX)
            return (int)long_ret;
        return INT_MAX;
    }
};
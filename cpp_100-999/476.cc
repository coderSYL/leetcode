// C++
// leetcode 476
// https://leetcode-cn.com/problems/number-complement/
// 


class Solution {
public:
    int findComplement(int num) {
        int big = 1 << 30;
        int res = 0;
        int base = 1;
        while(num > 0) {
            if(num % 2 == 0) {
                res += base;
            }
            num /= 2;
            if(base < big)
                base *= 2;
        }
        return  res;
    }
};
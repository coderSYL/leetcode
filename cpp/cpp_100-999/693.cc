// C++
// leetcode 693
// https://leetcode-cn.com/problems/binary-number-with-alternating-bits/

class Solution {
public:
    bool hasAlternatingBits(int n) {
        n = (n ^ (n>>1));
        while(n != 0) {
            if(n % 2 == 0)
                return false;
            n >>= 1;
        }
        return true;
    }
};
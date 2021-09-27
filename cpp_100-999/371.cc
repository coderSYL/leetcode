// C++
// leetcode 371
// https://leetcode-cn.com/problems/sum-of-two-integers/
// 


class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            auto c = ((unsigned int)a & b) << 1; // 都为1的加起来就进位
            a = a ^ b;  // 相同为0，不同为1，两个都是1的存到c里进位去了，这里就去掉了
            b = c;
        }

        return  a;
    }
};
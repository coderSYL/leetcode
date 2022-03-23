// C++
// leetcode 600
// https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
// 偷三叶的方法

class Solution {
public:
    int getHighBit(int n) { // 返回最高位是第几位，从0开始计数，例如1返回0，2返回1，4返回2，8返回3
        for(int i = 31; i >= 0; i--) {
            if((n>>i & 1) == 1) return  i;
        }
        return  -1; // never
    }

    int findIntegers(int n) { // n in [1, 10 ^ 9]
        int f[32][2];   // f[i][j] 表示二进制长度为i + 1，最高位即第i位为j的符合条件的个数
        f[0][0] = 1;
        f[0][1] = 1;
        for(int i = 0; i <= 30; i++) {
            f[i+1][0] = f[i][0] + f[i][1];
            f[i+1][1] = f[i][0];
        }

        int highBit = getHighBit(n);
        int res = 0;
        int preBit = 0;
        for(int i = highBit; i>= 0; i--) {
            int curBit = n>>i & 1;
            if(curBit == 1) {
                // 这bit为1
                 res += f[i][0];
                 if(preBit == 1)
                    break;
            }
            preBit = curBit;
            if(i == 0)
                res++;  // 到0的时候，
        }
        return  res;
    }
};
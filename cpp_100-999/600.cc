// C++
// leetcode 600
// https://leetcode-cn.com/problems/non-negative-integers-without-consecutive-ones/
// 偷三叶的方法

class Solution {
public:

    int getHighBit(int n) {
        for(int i = 31; i >= 0; i--) {
            if((n>>i & 1) == 1) return  i;
        }
        return  -1; // never
    }


    int findIntegers(int n) {
        int f[33][2];   // f[i][j] 表示二进制长度为i，最高位为j的复合条件的个数
        f[1][0] = 1;
        f[1][1] = 2;
        for(int i = 1; i <= 31; i++) {
            f[i+1][0] = f[i][1];
            f[i+1][1] = f[i][0] + f[i][1];
        }

        int highBit = getHighBit(n);
        int res = 0;
        int pre = 0;
        for(int i = highBit; i>= 0; i--) {
            int cur = n>>i & 1;
            if(cur == 1) {
                 res += f[i+1][0];
                 if(pre == 1)
                    break;
            }
            pre = cur;
            if(i == 0)
                res++;
        }
        return  res;
    }
};
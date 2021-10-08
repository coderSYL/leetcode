// C++
// leetcode 405
// https://leetcode-cn.com/problems/convert-a-nber-to-hexadecimal/
// 


class Solution {
public:
    string toHex(int num) {
        // 补码可能超过范围，所以用一个long来存
        long n = num;

        // 如果为负数，补一下
        if(n < 0)
            n += long(INT_MAX) * 2 + 2;

        // 为0，直接返回
        if(n == 0)
            return  "0";

        string  res = "";
        while(n > 0) {
            int yu = n % 16;
            char addToLeftSide;
            if(yu < 10) {
                addToLeftSide = '0' + yu;
            } else {
                addToLeftSide = 'a' + (yu - 10);
            }
            res = addToLeftSide + res;
            n /= 16;
        }

        
        return  res;
    }
};
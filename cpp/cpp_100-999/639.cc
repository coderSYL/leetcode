// C++
// leetcode 639
// https://leetcode-cn.com/problems/decode-ways-ii/
// 类斐波那契


class Solution {
public:
    int MOD = (int)1e9 + 7;
    int numDecodings(string s) {
        if(s[0] == '0')
            return  0;
        int n = s.size();
        // dp数组以及初始值设置
        char pre = s[0];
        long a = 1, b = (pre == '*' ? 9 : 1), c = -1;

        for(int i = 1; i < n; i++) {
            char c_loop = s[i];
            // 前一位
            if(c_loop == '0')
                c = 0;
            else
                c = b;
            if(c_loop == '*')
                c = (c * 9) % MOD;
            // 前两位
            if(pre == '1') {
                if(c_loop == '*')
                    c = (c + 9 * a) % MOD;
                else
                    c = (a + c) % MOD;
            }else if(pre == '2') {
                if(c_loop == '*')
                    c = (c + 6 * a) % MOD;
                else if(c_loop < '7')
                    c = (a + c) % MOD;
            } else if(pre == '*') {
                if(c_loop == '*') {
                    c = (c + 15 * a) % MOD;
                } else if(c_loop < '7') {
                    c = (c + 2 * a) % MOD;
                } else {
                    c = (a + c) % MOD;
                }
            }
            pre = c_loop;
            a = b;
            b = c;
        }
        return  b;
    }
};
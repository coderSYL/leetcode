// C++
// leetcode 91
// https://leetcode-cn.com/problems/decode-ways/
// 


class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return  0;
        int n = s.size();
        int a = 1, b = 1, c = -1;
        char pre = s[0];
        for(int i = 1; i < n; i++) {
            if(s[i] == '0')
                c = 0;
            else
                c = b;
            if(pre == '1') {
                c += a;
            } else if(pre == '2' && s[i] <'7') {
                c += a;
            }
            pre = s[i];
            a = b;
            b = c;
        }
        return  b;
    }
};
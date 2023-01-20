// C++
// leetcode 788
// https://leetcode.cn/problems/rotated-digits/


class Solution {
public:
    int isGood(int x) {
        int res = 0;
        while(x != 0) {
            int u = x % 10;
            x /= 10;
            if (u == 2 || u == 5 || u == 6 || u == 9)
                res = 1;
            else if (u != 0 && u != 1 && u != 8)
                return 0;
        }
        return res;
    }

    int rotatedDigits(int n) {
        int res = 0;
    	for (int i = 1; i <= n; i++)
            res += isGood(i);
        return res;
    }
};
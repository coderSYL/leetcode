// C++
// leetcode 926
// https://leetcode.cn/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') {
                r--;
                res = min(l+r, res);
            } else {
                l++;
                // 可以不判定，l自增，l + r 肯定比上一次要大
                // res = min(l+r, res); 
            }
        }
        res = res - r;
        return res;
    }
};
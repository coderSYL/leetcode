// C++
// leetcode 1422
// https://leetcode.cn/problems/maximum-score-after-splitting-a-string/

class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), cnt = 0, res = - n;
        for(int i = 0; i < n - 1; i++) {
            cnt += (s[i] == '0' ? 1 : 0);
            res = max(res, 2 * cnt + n - i - 1);
        }
        res -= cnt + (s[n-1] == '0' ? 1 : 0);
        return res;
    }
};
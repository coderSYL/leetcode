// C++
// leetcode 1021
// https://leetcode.cn/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        int cnt = 0, start_idx = 1;
        string res = "";
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                cnt++;
            } else {
                if(--cnt == 0) {
                    res += s.substr(start_idx, i-start_idx);
                    start_idx = i + 2;
                }
            }
        }
        return res;
    }
};
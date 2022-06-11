// C++
// leetcode 890
// https://leetcode.cn/problems/find-and-replace-pattern/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int a[26], b[26], n = words.size(), m = pattern.size();
        memset(a, -1, sizeof(a));
        vector<string> res;
        for(int i = 0; i < n; ++i) {
            string &s = words[i];
            if(s.size() != m)
                continue;
            memset(a, -1, sizeof(a));
            memset(b, -1, sizeof(b));
            bool ok = true;
            for(int j = 0; j < m; j++) {
                int c1 = s[j] - 'a', c2 = pattern[j] - 'a';
                if(a[c1] == -1 && b[c2] == -1) {
                    a[c1] = c2;
                    b[c2] = c1;
                } else if(a[c1] == c2 && b[c2] == c1) {
                    // do nothing
                } else {
                    ok = false;
                    break;
                }
            }
            if(ok)
                res.push_back(s);
        }
        return res;
    }
};
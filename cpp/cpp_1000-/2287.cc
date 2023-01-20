// C++
// leetcode 2287
// https://leetcode.cn/problems/rearrange-characters-to-make-target-string/

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt_s(26, 0);
        vector<int> cnt_t(26, 0);
        for(auto c : s) {
        	cnt_s[c - 'a']++;
        }
        for(auto c : target) {
        	cnt_t[c - 'a']++;
        }

        int res = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (cnt_t[i] == 0)
                continue;
        	res = min(cnt_s[i] / cnt_t[i], res );
        }
        return res;
    }
};
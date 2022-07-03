// C++
// leetcode 522
// https://leetcode.cn/problems/longest-uncommon-subsequence-ii/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size(), res = -1;
        for(int i = 0; i < n; i++) {
            int cur_size = strs[i].size();
            if(cur_size <= res) {
                continue;
            }
            bool ok = true;
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                if(check(strs[i], strs[j])) {
                    ok = false;
                    break;
                }
            }
            if(ok)
                res = cur_size;
        }
        return res;
    }

    // check if s1 is subsequence of s2
    bool check(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n2 < n1)
            return false;
        int i = 0;
        for(int j = 0; j < n2; j++) {
            if(s1[i] == s2[j])
                i++;
        }
        return i == n1;
    }
};
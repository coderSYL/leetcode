// C++
// leetcode 884
// https://leetcode-cn.com/problems/uncommon-words-from-two-sentences/

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        // 预处理统计s1,s2中的单词数量
        map<string, int> cnt;
        for (int i = 0, j = 0; i < s1.size(); ) {
            while (j < s1.size() && s1[j] != ' ') j++;
            cnt[s1.substr(i, j - i)]++;
            i = j + 1;
            j = i;
        }
        for (int i = 0, j = 0; i < s2.size(); ) {
            while (j < s2.size() && s2[j] != ' ') j++;
            cnt[s2.substr(i, j - i)]++;
            i = j + 1;
            j = i;
        }

        vector<string> res;
        for (auto& [k, v] : cnt) {
            if (v > 1) continue;
            res.push_back(k);
        }
        return res;
    }
};
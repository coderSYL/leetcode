// C++
// leetcode 1662
// https://leetcode.cn/problems/check-if-two-string-arrays-are-equivalent/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int j = 0, p = 0;
        for(int i = 0; i < word1.size(); i++) {
            for (auto & c : word1[i]) {
                if (j == word2.size() || c != word2[j][p]) {
                    return false;
                }
                if (++p == word2[j].size()) {
                    p = 0;
                    j++;
                }
            }
        }
        return j == word2.size();
    }
};
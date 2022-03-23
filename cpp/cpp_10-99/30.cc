// C++
// leetcode 30
// https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/
// 滑动窗口

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordsNum = words.size();
        if(s.size() == 0 || wordsNum == 0)
            return  res;
        int wordSize = words[0].size();

        // 预处理
        map<string, int>    noSame;
        for(auto word : words)
            noSame[word]++;

        for(int i = 0; i < wordSize && i < s.size(); i++) {
            int left = i;
            int right = i;
            int cnt = 0;
            map<string, int>    cur;

            while(right + wordSize <= s.size()) {
                string curWord = s.substr(right, wordSize);
                right += wordSize;

                if(noSame.find(curWord) != noSame.end()) {
                    // 该词存在
                    cur[curWord]++;
                    cnt++;

                    while(cur[curWord] > noSame[curWord]) {
                        string toBeDelete = s.substr(left, wordSize);
                        left += wordSize;
                        cur[toBeDelete]--;
                        cnt--;
                    }

                    if(cnt == wordsNum)
                        res.push_back(left);
                } else {
                    // 该词不存在
                    left = right;
                    cnt = 0;
                    cur.clear();
                    if(left + wordsNum * wordSize > s.size())
                        continue;
                }
            }
        }

        return  res;
    }
};
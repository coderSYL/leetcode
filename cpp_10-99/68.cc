// C++
// leetcode 68
// https://leetcode-cn.com/problems/text-justification/
// 


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int done = 0;
        vector<string> res;
        while(done < n) {
            int cur = 0;    // 已经选入的单词沾的字符数
            int wordNumThisLine = 0;
            bool specialMode = false;
            while(done + wordNumThisLine < n && cur + wordNumThisLine + words[done + wordNumThisLine].size() <= maxWidth) {
                // 计算本行最多装几个字母
                cur += words[done + wordNumThisLine].size();
                wordNumThisLine++;
            }


            // 计算是否为特殊模式，以及空格的大小
            // 特殊模式：一行只有一个词，或者是最后一行，表现为单词间空格大小全为1，左对齐
            specialMode = (done + wordNumThisLine == n || wordNumThisLine == 1);
            int spaceSize = (specialMode ? 1 : (maxWidth - cur) / (wordNumThisLine - 1) );
            int bigGap = (specialMode ? 0 :  maxWidth - cur - (wordNumThisLine - 1) * spaceSize );

            // 开始拼装并且插入到res结尾
            string line = words[done];
            int doneThisLine =  1;
            while(doneThisLine < wordNumThisLine) {
                int aSpace = spaceSize;
                if(bigGap > 0) {
                    aSpace++;
                    bigGap--;
                }
                line += string(aSpace, ' ');
                line += words[done + doneThisLine];
                doneThisLine++;
            }
            if(specialMode) {
                int spaceInTheEnd = maxWidth - line.size();
                line += string(spaceInTheEnd, ' ');
            }
            res.push_back(line);
            done += wordNumThisLine;
        }
        return  res;
    }
};
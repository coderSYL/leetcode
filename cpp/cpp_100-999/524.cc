// C++
// leetcode 524
// https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/
// 

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int len_s = s.size();
        string res;


        for(auto word : dictionary) {
            int len_word = word.size();
            if(len_word > len_s ||\
            (!res.empty() && res.size() > len_word) ||\
            (!res.empty() && res.size() == len_word && res < word))
                // word 比 s 长则不符合规定
                // 比现存res短，不行
                // 与现存res一样长，但是字典序大了，不行
                // 以上三种情况可直接跳过
                continue;
            int i = 0, j = 0;   // i for s, j for word
            while(j < len_word) {   // 每个循环找一个字符
                bool found = false;
                while(i < len_s) {
                    if(s[i] == word[j]) {
                        found = true;
                        break;  // 找到了
                    }
                    i++;
                }
                if(!found)  break;
                i++;
                j++;
            }
            if(j == len_word) {
                // j刷到了底部，可以刷新res
                res = word;
            }
        }

        return  res;
    }
};
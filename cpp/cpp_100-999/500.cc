// C++
// leetcode 500
// https://leetcode-cn.com/problems/keyboard-row/
// 逐个string判断
// 判断方法：
// 根据每个string的第一个字母判断所在键盘行，[q,a,z]行，判断后设int line = [0,1,2]
// 然后再将剩余字母分别判断是否在line行
// 若全在则将此string加到ret中去


class Solution {
public:
    // 把大写字母转换成小写字母
    char toSmall(char a){   
        int b = (int) a;
        if(b < 97)
            a = (char) (b + 32);
        return a;
    }

    // 判断字符c是否在字符串s中
    bool IsInLine(char c, string s){
        int size = s.size();
        for(int i = 0; i < size; i++){
            if(c == s[i])
                return true;
        }
        return false;
    }

    vector<string> findWords(vector<string>& words) {
        int size = words.size(), ssize =0, j =0;
        vector<string> q;
        q.push_back("qwertyuiop");
        q.push_back("asdfghjkl");
        q.push_back("zxcvbnm");

        int line = 3;
        bool ok = true;
        char temp = 'a';
        vector<string> ret;
        for(string s : words){
            ok = true;
            ssize = s.size();
            temp = toSmall(s[0]);
            if(IsInLine(temp,q[0]))
                line = 0;
            else if(IsInLine(temp,q[1]))
                line = 1;
            else
                line = 2;
            for(j = 1; j<ssize; j++){
                temp = toSmall(s[j]);
                if(!IsInLine(temp, q[line])){
                    ok =false;
                    break;
                }
            }
            if(ok)
                ret.push_back(s);
        }
        
        return ret;
    }
};
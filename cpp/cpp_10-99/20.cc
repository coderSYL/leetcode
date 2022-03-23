// C++
// leetcode 20
// url: https://leetcode-cn.com/problems/valid-parentheses/
// 思路:
// 用一个栈辅助处理字符串s
// 如果是左括号，入栈
// 如果是右括号，若栈空，false，栈非空，则出栈一个判断是否匹配，不匹配则false，匹配则处理下一个
// 处理完字符串后，若栈非空，false，栈空，true

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        vector<char> temp;
        int i =0;
        char c;
        while(i <size){
            c = s[i];
            if(c=='(' || c=='[' || c=='{')
            {
                temp.push_back(c);
            }
            else if(c==')')
            {   
                if(temp.empty())
                    return false;
                if(temp.back() =='(')
                {
                    temp.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if(c==']')
            {   
                if(temp.empty())
                    return false;
                if(temp.back() =='[')
                {
                    temp.pop_back();
                }
                else
                {
                    return false;
                }
            }
            else if(c=='}')
            {   
                if(temp.empty())
                    return false;
                if(temp.back() =='{')
                {
                    temp.pop_back();
                }
                else
                {
                    return false;
                }
            }
            i++;
        }   // end deal s
        return temp.empty();
    }
};
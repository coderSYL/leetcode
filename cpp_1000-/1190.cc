/*
 * C++
 * leetcode1190
 * url: https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/
 * 弄一个 vector<int> 当栈
 * 从左到右遍历目标string
 * 如果遇到 '('则把index入栈
 * 遇到')'则出栈一个index来配对，进行反转
 * 最后双指针处理一下多余的()
 */
#include <vector>

class Solution {
public:
    void re(char  *a, int start, int end){
        char temp;
        while(end > start){
            if(a[start] == '(')
                temp = ')';
            else if(a[start] == ')')
                temp = '(';
            else
                temp = a[start];

            if(a[end] == '(')
                a[start] = ')';
            else if(a[end] == ')')
                a[start] = '(';
            else
                a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }
    }

    string reverseParentheses(string s) {
        int size = s.size();
        char st[size];
        int i =0, j = size-1, l_temp;
        for(i = 0;i<size; i++)
            st[i] = s[i];
        vector<int> l;
        for(i = 0; i<size; i++){
            if(st[i] == '(')
                l.push_back(i);
            if(st[i] == ')'){
                l_temp = l.back()+1;
                l.pop_back();
                re(st, l_temp, i-1);
            }
        }

        i = 0;
        j = 0;
        while(i<size){
            if(st[i] =='(' || st[i] ==')'){
                i++;
            }else{
                st[j] = st[i];
                i++;
                j++;
            }
        }
        if(i==j)
            return s;
        st[j] = '\0';
        return st;
    }
};
// C++
// leetcode 678
// https://leetcode-cn.com/problems/valid-parenthesis-string/
// 一遍循环
// 遇左括号，入左栈
// 遇星星，入星栈
// 遇右括号，若左栈非空则出栈一个，若左栈空且星栈非空则星栈出一个，若都空则false
// 循环完毕后


class Solution {
public:
    bool checkValidString(string s) {
    	stack<int>	lefts;
    	stack<int>	stars;
    	int n = s.size();
    	for(int i = 0; i < n; i++) {
    		if(s[i] == '(') {
    			lefts.push(i);
    		} else if( s[i] == '*') {
    			stars.push(i);
    		} else {
    			if(!lefts.empty()) {
    				lefts.pop();
    			} else if(!stars.empty()) {
    				stars.pop();
    			} else {
    				return	false;
    			}
    		}
    	}

    	while(!lefts.empty()) {
    		if(stars.empty() || stars.top() < lefts.top()) {
    			return false;
    		} else {
    			lefts.pop();
    			stars.pop();
    		}
    	}

    	return	true;
    }
};
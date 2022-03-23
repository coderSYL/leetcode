// C++
// leetcode 1047
// https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/
// 入栈出栈完事

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        vector<char>    stack;
        int i = 0;
        while(i < n) {
            if(stack.empty()) {
                stack.push_back(s[i]);
            } else if(stack.back() == s[i]) {
                stack.pop_back();
            } else {
                stack.push_back(s[i]);
            }
            ++i;
        }
        return  string(stack.begin(), stack.end());
    }
};
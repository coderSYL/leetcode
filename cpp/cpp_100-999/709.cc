// C++
// leetcode 709
// https://leetcode-cn.com/problems/to-lower-case/

class Solution {
public:
    char toLower(char c) {
        if(c >= 'A' && c <= 'Z')
            return c-'A'+'a';
        return c;
    }
    
    string toLowerCase(string s) {
        int n = s.size();
        vector<char> tmp(n);
        int i = 0;
        for(auto c : s) tmp[i++] = toLower(c);
        return string(tmp.begin(), tmp.end());
    }
};
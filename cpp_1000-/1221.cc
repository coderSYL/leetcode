// C++
// leetcode 1221
// https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/
// 

class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        char L = 'L';
        char R = 'R';
        int cur = 0;
        int res = 0;
        for(auto c : s) {
            if(c == L)  cur++;
            else        cur--;
            if(cur == 0)    res++;
        }
        return  res;
    }
};
// C++
// leetcode 482
// https://leetcode-cn.com/problems/license-key-formatting/
// 


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int numOf_ = 0;
        for(auto c : s)
            if(c == '-')
                numOf_++;
        string res = "";
        int left = (s.size() - numOf_) % k;
        if(left == 0)
            left = k;
        for(auto c : s) {
            if(c == '-')
                continue;
            if(left == 0) {
                res.push_back('-');
                left = k;
            }
            char one = c;
            if(one >= 'a' && one <= 'z')
                one = one - 'a' + 'A';
            res.push_back(one);
            left--;
        }
        return  res;
    }
};
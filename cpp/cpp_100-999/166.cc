// C++
// leetcode 166
// https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
// 
#include <string>

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long up = numerator;
        long down = denominator;
        if(up % down == 0)
            return  to_string(up / down);
        string res = "";
        if(up * down < 0)
            res = "-";
        if(up < 0)
            up = -up;
        if(down < 0)
            down = -down;
        res = res + to_string(up / down) + ".";
        up = up % down;
        unordered_map<long, int>    m;
        while(up != 0) {
            m[up] = res.size();
            res.push_back((char)((up * 10) / down) + '0');
            up = (up * 10) % down;
            if(m.find(up) != m.end()) {
                // 有循环了
                res.insert(m[up], "(");
                res.push_back(')');
                return  res;
            }
        }
        return  res;
    }
};
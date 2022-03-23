// C++
// leetcode 171
// https://leetcode-cn.com/problems/excel-sheet-column-number/
// 简单

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size() - 1;
        int base = 1;
        int res = 0;
        while(n >= 0) {
            int temp = ((int)(columnTitle[n])) - 64;
            res += base * temp;
            if(n > 0)
                base *= 26;
            --n;
        }
        return  res;
    }
};
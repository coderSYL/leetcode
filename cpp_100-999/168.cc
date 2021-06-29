// C++
// leetcode 168
// https://leetcode-cn.com/problems/excel-sheet-column-title/
// 可以递归，也可以循环，我写的是循环

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0)
        {
            --columnNumber;
            res = (char)(65 + columnNumber % 26) + res;
            columnNumber /= 26;
        }
        return res;
    }
};
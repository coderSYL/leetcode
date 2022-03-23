// C++
// leetcode 292
// https://leetcode-cn.com/problems/nim-game/
// 根据dp的关系可以找到规律
// 算 1 到 n是否能赢
// i是否能赢取决于 i-1 i-2 i-3 中是否有输的，如果有，则让对手到输的数中
// 由此发现规律：从 1 开始，赢赢赢输，赢赢赢输，赢赢赢输


class Solution {
public:
    bool canWinNim(int n) {
        n = n % 4;
        if(n == 0)  return  false;
        return  true;
    }
};
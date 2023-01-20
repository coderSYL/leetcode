// C++
// leetcode 1812
// https://leetcode.cn/problems/determine-color-of-a-chessboard-square/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a', y = coordinates[1] - '1';
        if ((x + y) % 2== 0)
            return false;
        return true;
    }
};
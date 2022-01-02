// C++
// leetcode 390
// https://leetcode-cn.com/problems/elimination-game/
// 当前剩余数组肯定是等差数列，等差数列的信息可以用 首项，公差，项数 三个信息表示

class Solution {
public:
    int lastRemaining(int n) {
        // start 首项，gap 公差，remain 当前剩余个数
        int start = 1, gap = 1, remain = n;
        bool up = true;
        while(remain > 1) {
            if(up || remain & 1)    // 从左到右 or (从右到左 且剩奇数项)时，需要删除首项
                start += gap;
            up = !up;
            gap *= 2;
            remain >>= 1;
        }
        return start;
    }
};
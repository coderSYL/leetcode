// C++
// leetcode 62
// https://leetcode-cn.com/problems/unique-paths/
// 


class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalStep = m + n - 2;
        int small = min(m, n) - 1;
        long up = 1, down = 1;
        while(small > 0) {
            up *= totalStep--;
            down *= small--;
        }
        return  (int)(up / down);
    }
};
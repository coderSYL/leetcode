// C++
// leetcode 441
// https://leetcode-cn.com/problems/arranging-coins/
// 


class Solution {
public:
    int arrangeCoins(int n) {
        long l = 1, r = n;
        while(l <= r) {
            long mid = (l + r) / 2;
            long m = (long)(mid + 1) * mid / 2;
            if(m > n) {
                r = mid - 1;
                continue;
            }
            m += mid + 1;
            if(m > n) {
                return  mid;
            } else {
                l = mid + 1;
                continue;
            }
        }
        return -1;  // never
    }
};
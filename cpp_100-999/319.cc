// C++
// leetcode 319
// https://leetcode-cn.com/problems/bulb-switcher/

class Solution {
public:
    int mySqrt(int x) {
        if(x >= 2147395600)
            return 46340;
        long xx = x;
        long l = 1, r = xx;
        while(l <= r) {
            long mid = (l + r) / 2;
            if(mid * mid > xx) {
                r = mid - 1;
            } else if(mid * mid < xx) {
                l = mid + 1;
            } else {
                return  mid;
            }
        }
        return r;
    }

    int bulbSwitch(int n) {
        return  mySqrt(n);
    }
};
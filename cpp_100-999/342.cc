/*
 * C++
 * leetcode 342
 * url: https://leetcode-cn.com/problems/power-of-four/
 * 分情况讨论
 * <=0, false
 * >0,  loop(如果能被4整除, 就除以4），判断最后是否为1，是的话true，否则false
 */

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        while(n%4==0){
                n = n/4;
        }
        if(n==1)
            return true;
        return false;
    }
};
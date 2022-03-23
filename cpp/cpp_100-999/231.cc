/*
 * C++
 * leetcode 231
 * url: https://leetcode-cn.com/problems/power-of-two/
 * 若n为非正数，false
 * 然后循环判断：
 * 若 %2==0，则除以二
 * 循环终止后判断剩下的数是否为1
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        while(n!=1 && n%2==0){
            n = n>>1;
        }
        if(n==1)
            return true;
        return false;
    }
};
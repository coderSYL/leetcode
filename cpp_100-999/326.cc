// C++
// leetcode 326
// https://leetcode-cn.com/problems/power-of-three/
// 简简单单，不多说


class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)  return  false;

        while(n > 1) {
            if(n % 3 == 0)  n = n / 3;
            else    return  false;
        }
        
        return  true;
    }
};
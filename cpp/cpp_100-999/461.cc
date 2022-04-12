// C++
// leetcode 461
// https://leetcode-cn.com/problems/hamming-distance/
// 直接对两个数x,y进行32位里每个位置是否相等的判断，不等则 res++

class Solution {
public:
    int hammingDistance(int x, int y) {
        int i = 0,res = 0;
        while(i<32){
            if(x%2 != y%2)
                res++;
            i++;
            x = x/2;
            y = y/2;
        }
        return res;
    }
};
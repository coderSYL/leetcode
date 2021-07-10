// C++
// leetcode 190
// https://leetcode-cn.com/problems/reverse-bits/
// 简简单单用一个bool数组完成

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bool bit[32];
        for(int i = 0; i < 32; ++i, n/=2) {
        	if(n % 2 == 1)
        		bit[i] = true;
        	else
        		bit[i] = false;
        }
        n = 0;
        uint32_t temp = 1;
        for(int i = 31; i >=0; --i) {
        	if(bit[i])
        		n +=temp;
        	temp *=2;
        }
        return n;
    }
};
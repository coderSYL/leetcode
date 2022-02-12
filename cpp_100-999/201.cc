// C++
// leetcode 201
// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    	while(left < right)
    		right &= (right-1);
    	return right;
    }
};
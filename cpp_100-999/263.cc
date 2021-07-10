// C++
// leetcode 263
// https://leetcode-cn.com/problems/ugly-number/
// 简简单单

class Solution {
public:
    bool isUgly(int n) {
        if(n < 1)   return false;
    	while(n % 2 == 0)   n /= 2;
    	while(n % 3 == 0)   n /= 3;
    	while(n % 5 == 0)   n /= 5;
    	return (n == 1);
    }
};
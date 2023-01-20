// C++
// leetcode 1780
// https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/

class Solution {
public:
    bool checkPowersOfThree(int n) {
    	while(n > 0) {
    		if (n % 3 == 2)
    			return false;
    		n /= 3;
    	}
    	return true;
    }
};
// C++
// leetcode 754
// https://leetcode.cn/problems/reach-a-number/

class Solution {
public:
    int reachNumber(int target) {
    	if (target < 0)
    		target = -target;
    	int k = 0, now = 0;
    	while (now < target) {
    		now += ++k;
    	}

    	int diff = now - target;
    	while(diff % 2 != 0) {
    		diff += ++k;
    	}
    	return k;
    }
};
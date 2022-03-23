// C++
// leetcode 1342
// https://leetcode-cn.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps(int num) {
    	int res = 0;
    	while(num > 0) {
    		if(num & 1 == 1) num--;
    		else num >>= 1;
    		res++;
    	}
    	return res;
    }
};
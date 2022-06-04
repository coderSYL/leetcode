// C++
// leetcode 829
// https://leetcode.cn/problems/consecutive-numbers-sum/

class Solution {
public:
    int consecutiveNumbersSum(int n) {
    	int res = 0, cur = 1, sum = 1;
    	while(sum <= n) {
    		if((n-sum) % cur == 0)
    			res++;
    		cur++;
    		sum += cur;
    	}
    	return res;
    }
};
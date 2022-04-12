// C++
// leetcode 357
// https://leetcode-cn.com/problems/count-numbers-with-unique-digits/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
    	int good = 9;
    	int cur = 9;
    	while(n--) {
    		res += cur;
    		cur *= good--;
    	}
    	return res;
    }
};
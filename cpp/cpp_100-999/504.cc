// C++
// leetcode 504
// https://leetcode-cn.com/problems/base-7/

class Solution {
public:
    string convertToBase7(int num) {
    	if(num == 0) return "0";
    	bool isNegative = false;
    	if(num < 0) {
    		isNegative = true;
    		num = -num;
    	}
    	string res = "";
    	while(num > 0) {
    		int tmp = num% 7;
    		num /= 7;
    		res = (char)('0' + tmp) + res;
    	}
    	if(isNegative)
    		res = "-" + res;
    	return res;
    }
};
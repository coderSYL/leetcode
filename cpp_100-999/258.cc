// C++
// leetcode 258
// https://leetcode-cn.com/problems/add-digits/
// easy

class Solution {
public:
    int addDigits(int num) {
    	while(num >= 10) {
    		string s = to_string(num);
    		num = 0;
    		for(auto & c : s) {
    			num += c-'0';
    		}
    	}
    	return num;
    }
};
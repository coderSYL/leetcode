// C++
// leetcode 537
// https://leetcode-cn.com/problems/complex-number-multiplication/

class Solution {
public:
	// 判断一个字符是否在0-9之中
	// 是则返回true，不是则返回false
	bool isNum(char c) {
		if(c > '9' || c < '0') return false;
		return true;
	}

    string complexNumberMultiply(string num1, string num2) {
    	int plus1 = 1, plus2 = 1;
    	while(isNum(num1[plus1]))
    		plus1++;
    	while(isNum(num2[plus2]))
    		plus2++;
    	int real1 = stoi(num1), real2 = stoi(num2);
    	int comp1 = stoi(num1.substr(plus1 + 1));
    	int comp2 = stoi(num2.substr(plus2 + 1));
    	int realRes = real1 * real2 - comp1 * comp2;
    	int compRes = real1 * comp2 + real2 * comp1;
    	return to_string(realRes) + "+" + to_string(compRes) + "i";
    }
};
// C++
// leetcode 125
// https://leetcode-cn.com/problems/valid-palindrome/

class Solution {
public:
	char toSmall(char c) {
		// 将大写字符变为小写
		// 数字字符不变，其他字符一律变为 '.'
		if(c <= 'Z' && c >= 'A')
			return c - 'A' + 'a';
		if(c <= 'z' && c >= 'a')
			return c;
		if(c <= '9' && c >= '0')
			return c;
		return '.';
	}

    bool isPalindrome(string s) {
    	int i = 0, j = s.size() - 1;
    	while(i < j) {
    		while(i < s.size() && toSmall(s[i]) == '.')
    			++i;
    		while(j >= 0 && toSmall(s[j]) == '.')
    			--j;
    		if(i >= j) return	 true;
    		if(toSmall(s[i]) != toSmall(s[j]))
    			return	 false;
    		++i;
    		--j;
    	}
    	return	true; // never
    }
};
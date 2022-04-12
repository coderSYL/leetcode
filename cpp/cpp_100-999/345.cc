// C++
// leetcode 345
// https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
// 用一个字符数组来进行操作，操作完了再改成字符串
// 操作方法，从前和从后扫描，如果不是元音字母直接填装，如果是，则前后互换，直到全都填过

class Solution {
public:
	bool isGood(char& c) {
		if(c == 'a' || c == 'e' ||  c == 'i' ||  c == 'o' ||  c == 'u' ||
			 c == 'A' || c == 'E' ||  c == 'I' ||  c == 'O' ||  c == 'U')
			return	true;
		return	false;
	}

    string reverseVowels(string s) {
    	int n = s.size();
    	if(n == 1)
    		return	s;
    	char ss[n];
    	int i = 0, j = n -1;

    	while(i <= j) {
	    	while(i < n && !isGood(s[i])) {
	    		ss[i] = s[i];
	    		i++;
	    	}
	    	while(i < j && !isGood(s[j])) {
	    		ss[j] = s[j];
	    		j--;
	    	}
	    	// 到现在，s[i]与s[j]都是元音字母
	    	if(i <= j) {
	    		ss[i] = s[j];
	    		ss[j] = s[i];
	    	}
	    	i++;
	    	j--;
	    }
	    return string(ss, ss+n);
    }
};
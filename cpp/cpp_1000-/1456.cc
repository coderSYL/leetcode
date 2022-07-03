// C++
// leetcode 1456
// https://ssg.leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
	bool isVowel(char c) {
		switch (c) {
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' :
				return true;
				break;
		}
		return false;
	}

    int maxVowels(string s, int k) {
    	int cur = 0, n = s.size(), res = 0;
    	for(int i = 0; i < n; i++) {
    		if(i >= k && isVowel(s[i-k])) {
    			cur--;
    		}
    		if(isVowel(s[i])) {
    			res = max(res, ++cur);
    		}
    	}
    	return res;
    }
};
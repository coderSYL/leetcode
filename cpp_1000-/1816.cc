// C++
// leetcode 1816
// https://leetcode-cn.com/problems/truncate-sentence/

class Solution {
public:
	bool isLetter(char c) {
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
			return true;
		return false;
	}
    string truncateSentence(string s, int k) {
    	int end = 0;
    	while(k > 0) {
    		end++;
    		while(end < s.size() && isLetter(s[end]))
    			end++;
    		--k;
    	}
    	return s.substr(0, end);
    }
};
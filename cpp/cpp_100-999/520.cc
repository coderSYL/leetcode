// C++
// leetcode 520
// https://leetcode-cn.com/problems/detect-capital/

class Solution {
public:
    bool detectCapitalUse(string word) {
    	if(word.size() == 1)
    		return	true;
    	bool firstBig = word[0] < 'a';
    	bool leftBig = word[1] < 'a';
    	if(!firstBig && leftBig)
    		return	false;
    	for(int i = 2; i < word.size(); i++) {
    		if(leftBig ^ (word[i] < 'a') == 1)
    			return	false;
    	}
    	return	true;
    }
};
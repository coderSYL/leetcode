// C++
// leetcode 周赛 2021-07-18
// https://leetcode-cn.com/contest/weekly-contest-250/problems/maximum-number-of-words-you-can-type/
// 第一题

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
    	// 统计 text
    	bool haveAGoodWord = true;
    	vector<bool> broken(26, false);
    	for(auto c : brokenLetters) {
    		broken[(int)(c - 'a')] = true;
   		}
   		int res = 0;
   		for(auto c : text) {
   			if(c == ' ') {
   				// 为空格，结算
   				if(haveAGoodWord)
   					++res;
   				haveAGoodWord = true;
   				continue;
   			} else {
   				// 为非空格
   				if(!haveAGoodWord)
   					continue;
   				if(broken[(int)(c - 'a')])
   					haveAGoodWord = false;
   			}
   		}
   		// 由于结尾没有空格，需要再结算一次
   		if(haveAGoodWord)
   			++res;
   		return	res;
    }
};
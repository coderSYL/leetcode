// C++
// leetcode 434
// https://leetcode-cn.com/problems/number-of-segments-in-a-string/
// 遍历一遍
// 除了第一个单词外，之后每个单词都出现在空格之后，可以用一个bool来记录前面的格子是不是空格，且初始化为true


class Solution {
public:
    int countSegments(string s) {
    	bool beforeIsSpace = true;
    	int res = 0;
    	for(auto c : s) {
    		if(c == ' ') {
    			beforeIsSpace = true;
    		} else {
    			if(beforeIsSpace)
    				res++;
    			beforeIsSpace = false;
    		}
    	}
    	return	res;
    }
};
// C++
// leetcode 806
// https://leetcode-cn.com/problems/number-of-lines-to-write-string/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
    	int line = 1, cur = 0;
    	for(auto & c : s) {
    		int u = widths[c - 'a'];
    		cur += u;
    		if(cur > 100) {
    			line++;
    			cur = u;
    		}
    	}
    	return vector<int>{line, cur};
    }
};
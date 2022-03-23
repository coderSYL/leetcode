// C++
// leetcode 1614
// https://leetcode-cn.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
    	int res = 0;
    	int n = s.size();
    	int cur = 0;
    	for(int i = 0; i < n; ++i) {
    		if(s[i] == '(') {
    			++cur;
    		} else if(s[i] == ')') {
    			res = max(res, cur);
    			--cur;
    		}
    	}
    	return res;
    }
};
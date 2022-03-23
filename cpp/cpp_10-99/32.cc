// C++
// leetcode 32
// https://leetcode-cn.com/problems/longest-valid-parentheses/
// dp，想起来有点困难

class Solution {
public:
    int longestValidParentheses(string s) {
    	if(s.size() == 0)	return	0;
    	int res = 0;
    	// dp[i] 表示以第 i 位结尾的最大合法子串的长度
    	int dp[s.size()];
    	dp[0] = 0;
    	bool beforeIsLeft = (s[0] == '(');
    	for(int i = 1; i < s.size(); i++) {
    		// 主要讨论依据：这一位与前一位
    		// 复杂情况，s[i] 与 s[i - 1] 都是右括号，需要查更前面的dp的值
    		if(s[i] == '(') {
    			dp[i] = 0;
    			beforeIsLeft = true;
    		} else {
    			if(beforeIsLeft) {
    				dp[i] = 2 + (i > 1 ? dp[i - 2] : 0);
    			} else {
    				int idxToCheck = i - dp[i - 1] - 1;
    				if(idxToCheck >= 0 && s[idxToCheck] == '(') {
    					dp[i] = dp[i - 1] + 2;
    					if(idxToCheck > 0)
    						dp[i] += dp[idxToCheck - 1];
    				} else {
    					dp[i] = 0;
    				}
    			}
    			beforeIsLeft = false;
    		}
    		res = max(res, dp[i]);
    	}
    	return	res;
    }
};
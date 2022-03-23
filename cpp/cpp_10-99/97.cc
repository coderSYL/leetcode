// C++
// leetcode 97
// https://leetcode-cn.com/problems/interleaving-string/
// 用dfs试了下，size过大会超时，所以改用了二维dp

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if(s1.size() + s2.size() != s3.size())
    		return	 false;

    	vector<vector<bool>>	dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
    	dp[0][0] = true;
    	for(int i = 0; i < s1.size(); i++) {
    		if(s1[i] == s3[i])
    			dp[i + 1][0] = true;
    		else
    			break;
    	}
    	for(int i = 0; i < s2.size(); i++) {
    		if(s2[i] == s3[i])
    			dp[0][i + 1] = true;
    		else
    			break;
    	}

    	for(int i = 0; i < s3.size(); i++) {
    		char c = s3[i];
    		int a = max(1, i + 1 - (int)s2.size()), b = i + 1 - a;
    		while(a <= s1.size() && b > 0) {
    			if(dp[a - 1][b] && s1[a - 1] == c) {
    				dp[a][b] = true;
    			} else if(dp[a][b - 1] && s2[b - 1] == c) {
    				dp[a][b] = true;
    			}
    			a++;
    			b--;
    		}
    	}
    	return	dp[s1.size()][s2.size()];
    }
};
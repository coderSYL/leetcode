// C++
// leetcode 1781
// https://leetcode.cn/problems/sum-of-beauty-of-all-substrings/solution/

class Solution {
public:
    int beautySum(string s) {
    	int n = s.size();
    	int cnt[n+1][26];
        int res = 0;
    	for (int i = 0; i < 26; i++)
    		cnt[0][i] = 0;

    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < 26; j++) {
    			cnt[i + 1][j] = cnt[i][j];
    		}
    		cnt[i+1][s[i] - 'a']++;
    	}

    	for (int i = 0; i < n; i++) {
    		for (int j = i + 2; j <= n; j++) {
    			int ma = 0, mi = INT_MAX;
    			for (int k = 0; k < 26; k++) {
    				int u = cnt[j][k] - cnt[i][k];
    				if (u == 0)
    					continue;
    				ma = max(ma, u);
    				mi = min(mi, u);
    			}
    			res += ma - mi;
                // cout<<i<<" till "<<j<<" : "<<ma<<" and "<<mi<<endl;
    		}
    	}
    	return res;
    }
};
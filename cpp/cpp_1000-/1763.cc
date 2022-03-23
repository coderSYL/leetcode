// C++
// leetcode 1763
// https://leetcode-cn.com/problems/longest-nice-substring/

class Solution {
public:
    string longestNiceSubstring(string s) {
    	int n = s.size();
    	int cnt[n+1][128];
        memset(cnt, 0, sizeof(cnt));
    	for(int i = 1; i <= n; i++) {
    		char c = s[i-1];
    		memcpy(cnt[i], cnt[i-1], sizeof(cnt[0]));
    		cnt[i][c-'A']++;
    	}
    	int idx = -1, len = 0;
    	for(int i = 0; i < n; i++) {
    		for(int j = i + 1; j < n;j++) {
    			if(j - i + 1 <= len)
    				continue;
    			int *a = cnt[i], *b = cnt[j+1];
    			if(check(a, b)) {
    				idx = i;
    				len = j - i + 1;
    			}
    		}
    	}
        return idx == -1 ? "" : s.substr(idx, len);
    }

    bool check(int *a, int *b) {
    	for(int i = 0; i < 26; i++) {
    		int low = b[i]-a[i], up = b[i + 32] - a[i+32];
    		if(low ==0 && up > 0) return false;
    		if(up ==0 && low > 0) return false;
    	}
    	return true;
    }
};
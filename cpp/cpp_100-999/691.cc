// C++
// leetcode 691
// https://leetcode.cn/problems/stickers-to-spell-word/
// dp

class Solution {
public:
	int full;
    int minStickers(vector<string>& stickers, string target) {
    	int n = target.size(), m = stickers.size();
    	full = (1<<n) - 1;
    	vector<int> info(n);
    	for(int i = 0; i < n; i++) {
    		info[i] = target[i] - 'a';
    	}
    	vector<int> f(full+1, -1);
    	f[0] = 0;
    	int cnt[26], tmp[26];
    	for(int i = 0; i < m; i++) {
    		// 每次处理一个单词
    		memset(cnt, 0, sizeof(cnt));
    		string &s = stickers[i];
    		for(int j = 0; j < s.size(); ++j) {
    			cnt[s[j] - 'a']++;
    		}
    		for(int j = 0; j < full; j++) {
    			if(f[j] == -1)
    				continue;
    			memcpy(tmp, cnt, sizeof(tmp));
    			int after = j;
    			for(int pos = 0; pos < n; pos++) {
    				if((j>>pos) & 1 == 1)
    					continue;
    				int u = info[pos];
    				if(tmp[u] > 0) {
    					tmp[u]--;
    					after |= (1<<pos);
    				}
    			}
    			if(after != j) {
    				if(f[after] == -1)
    					f[after] = f[j]+1;
    				else
    					f[after] = min(f[after], f[j] + 1);
    			}
    		}
    	}
    	return f[full];
    }
};
// C++
// leetcode 424
// https://leetcode-cn.com/problems/longest-repeating-character-replacement/

class Solution {
public:
	int characterReplacement(string s, int k) {
		int cnt[26] = {0}, n = s.size(), res = 0;
		int maxNow = 1;
		for (int i = 0, j = 0; j < n; j++) {
			int u = s[j] - 'A';
			cnt[u]++;
			maxNow = max(maxNow, cnt[u]);
			while(j - i + 1 - maxNow > k) {
				cnt[s[i] - 'A']--;
				i++;
			}
			res = max(res, j - i + 1);
		}
		return res;
	}
};
// C++
// leetcode 2185
// https://leetcode.cn/problems/counting-words-with-a-given-prefix/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), res = 0;
        for (auto s : words) {
        	if (s.size() < n)
        		continue;
        	bool ok = true;
        	for (int i = 0; i < n; i++) {
        		if (s[i] != pref[i]) {
        			ok = false;
        			break;
        		}
        	}
        	if (ok)
        		res++;
        }

        return res;
    }
};
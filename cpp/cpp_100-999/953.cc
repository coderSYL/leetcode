// C++
// leetcode 953
// https://leetcode.cn/problems/verifying-an-alien-dictionary/

class Solution {
public:
	int getIdx[26];
	bool judge(string &s1, string &s2) {
		int n1 = s1.size(), n2 = s2.size(), n = min(n1, n2);
		for(int i = 0; i < n; i++) {
			int u1 = getIdx[s1[i] - 'a'], u2 = getIdx[s2[i] - 'a'];
			if(u1 < u2)
				return true;
			else if(u1 > u2)
				return false;
		}
		return n1 <= n2;
	}

    bool isAlienSorted(vector<string>& words, string order) {
    	int n = words.size(), m = order.size();
    	for(int i = 0; i < m; i++)
    		getIdx[order[i]-'a'] = i;

    	for(int i = 0; i < n-1; i++) {
    		if(!judge(words[i], words[i+1]))
    			return false;
    	}
    	return true;
    }
};
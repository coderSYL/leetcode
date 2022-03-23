// C++
// leetcode 205
// https://leetcode-cn.com/problems/isomorphic-strings/

class Solution {
public:
	vector<int> sTot;
	vector<int> tTos;
    bool isIsomorphic(string s, string t) {
    	int n = s.size();
    	sTot.resize(129, 1000);
    	tTos.resize(129, 1000);
    	for(int i = 0; i < n; i++) {
    		int ss = s[i];
    		int tt = t[i];
    		if(sTot[ss] == 1000) {
    			sTot[ss] = tt;
    			if(tTos[tt] != 1000) return false;
    			tTos[tt] = ss;
    		} else {
    			if(sTot[ss] != tt) return false;
    			if(tTos[tt] != ss) return false;
    		}
    	}
    	return true;
    }
};
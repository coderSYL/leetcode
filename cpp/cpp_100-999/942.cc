// C++
// leetcode 942
// https://leetcode.cn/problems/di-string-match/

class Solution {
public:
    vector<int> diStringMatch(string s) {
    	int n = s.size();
    	vector<int> res(n+1);
    	int l = 0, r = n;
    	for(int i = 0; i < n; ++i) {
    		res[i] = (s[i] == 'I' ? l++ : r--);
    	}
    	res[n] = l;
    	return res;
    }
};
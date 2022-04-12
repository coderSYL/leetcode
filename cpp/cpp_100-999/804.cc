// C++
// leetcode 804
// https://leetcode-cn.com/problems/unique-morse-code-words/

class Solution {
public:
	string toMorse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

	long getIdx(string &s) {
		string tmp = "";
		int n = s.size();
		long res = 1;
		for(int i = 0; i < n; i++) {
			string &ss = toMorse[s[i] - 'a'];
			int m = ss.size();
			for(int i = 0; i < m; i++) {
				int u = (ss[i] == '.' ? 1 : 0);
				res = (res<<1) + u;
			}
		}
		return res;
	}

    int uniqueMorseRepresentations(vector<string>& words) {
    	set<long> s;
    	for(auto &st : words)
    		s.insert(getIdx(st));
    	return s.size();
    }
};
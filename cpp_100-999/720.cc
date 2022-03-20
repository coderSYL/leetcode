// C++
// leetcode 720
// https://leetcode-cn.com/problems/longest-word-in-dictionary/

class Solution {
public:
	static bool cmp(const string& s1, const string& s2) {
		return s1.size() < s2.size(); //从小到大排序
	}
	int idx = 0;
	int trie[30010][26] = {0};
	bool isEnd[30010] = {0};

	// 添加成功返回bool
	bool add(string s) {
		int p = 0, n = s.size();
		for(int i = 0; i < n-1; i++) {
			int u = s[i] - 'a';
			if(trie[p][u] == 0) return false;
			p = trie[p][u];
		}
		trie[p][s[n-1] - 'a'] = ++idx;
		isEnd[idx] = true;
		// cout<<s<<" inserted ! "<<endl;
		return true;
	}
	string longestWord(vector<string>& words) {
		sort(words.begin(), words.end(), cmp);
		string res = "";
		for(auto &s : words) {
			if(add(s)) {
				if(s.size() > res.size())
					res = s;
				else if(res.compare(s)>0)
					res = s;
			}
		}
		return res;
	}
};
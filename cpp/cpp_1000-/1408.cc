// C++
// leetcode 1408
// https://leetcode.cn/problems/string-matching-in-an-array/

class Solution {
public:
	int trie[45009][26];
	int idx = 0;

	void insert(string &s,int cur) {
		int p = 0;
		for(int i = cur; i < s.size(); i++) {
			int u = s[i] - 'a';
			if(trie[p][u] == 0)
				trie[p][u] = ++idx;
			p = trie[p][u];
		}
	}

	bool search(string s) {
		int p = 0;
		for(int i = 0; i < s.size(); i++) {
			int u = s[i] - 'a';
			if(trie[p][u] == 0)
				return false;
			p = trie[p][u];
		}
		return true;
	}

	bool searchAndInsert(string &s) {
		if (search(s))
			return true;

		int n = s.size();
		for(int i = 0; i < n; i++) {
			insert(s, i);
		}
		return false;
	}

	static bool cmp(string a, string b) {
		return a.size() > b.size();
	}

    vector<string> stringMatching(vector<string>& words) {
    	sort(words.begin(), words.end(), cmp);
    	vector<string> res;
    	for(auto &s : words) {
    		if (searchAndInsert(s))
    			res.push_back(s);
    	}

    	return res;
    }
};



// // 方法二
// class Solution {
// public:
// 	// judge if string a contains b
// 	bool contain(string &a, string &b) {
// 		int lenA = a.size(), lenB = b.size();
// 		for (int i = 0; i <= lenA - lenB; i++) {
// 			bool ok = true;
// 			for (int j = 0; j < lenB; j++) {
// 				if (a[i + j] != b[j]) {
// 					ok = false;
// 					break;
// 				}
// 			}
// 			if (ok)
// 				return true;
// 		}
// 		return false;
// 	}

//     vector<string> stringMatching(vector<string>& words) {
//     	int n = words.size();
//     	vector<string> res;
//     	for (int i = 0; i < n; i++) {
//     		for (int j = 0; j < n; j++) {
//     			if (words[j].size() <= words[i].size())
//     				continue;
//     			if (contain(words[j], words[i])) {
//     				res.push_back(words[i]);
//     				break;
//     			}
//     		}
//     	}

//     	return res;
//     }
// };
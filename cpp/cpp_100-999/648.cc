// C++
// leetcode 648
// https://leetcode.cn/problems/replace-words/
// 字典树

class Solution {
public:
	// int N = 100009;
	int trie[100009][26];
	int count[100009];
	int idx = 0;

	void insert(string s) {
		int p = 0;
		for(int i = 0; i < s.size(); i++) {
			int u = s[i] - 'a';
			if(trie[p][u] == 0)
				trie[p][u] = ++idx;
			p = trie[p][u];
		}
		count[p]++;
        // cout<<s<<" inserted"<<endl;
	}

	string searchPre(string s) {
		int p = 0;
		for(int i = 0; i < s.size(); i++) {
			int u = s[i] - 'a';
			if(trie[p][u] == 0) {
				if(i == 0 || count[p] == 0) {
					return s;
				}
			}

			if(count[p] != 0) {
				return s.substr(0, i);
			}
			p = trie[p][u];
		}
		return s;
	}

    string replaceWords(vector<string>& dictionary, string sentence) {
    	memset(trie, 0, sizeof(trie));
    	for(auto &s : dictionary) {
    		insert(s);
    	}
    	int n = sentence.size();
    	string res = "";
    	for(int i = 0; i < n; ) {
    		int j = i;
    		while(j < n && sentence[j] != ' ') {
    			j++;
    		}
    		// string cur = sentence.substr(i, j - i);
    		// cout<<"searching "<<cur<<endl;
    		res += searchPre(sentence.substr(i, j - i));
    		if(j != n) {
    			res += " ";
    		}
    		i = j + 1;
    	}
    	return res;
    }
};
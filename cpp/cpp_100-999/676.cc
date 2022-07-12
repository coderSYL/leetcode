// C++
// leetcode 676
// https://leetcode.cn/problems/implement-magic-dictionary/

class MagicDictionary {
public:
	int trie[10009][26];
	int count[10009];
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
	}

	bool searchP(int p, string &s, int cur, int changed) {
		if(changed > 1)
			return false;
		if(cur == s.size()) {
			// 结算
			if(count[p] > 0)
				return changed == 1;
			// 不是尾巴，false
			return false;
		}

		int u = s[cur] - 'a';
		for(int i = 0; i < 26; i++) {
			if(trie[p][i] == 0)
				continue;
			if (searchP(trie[p][i], s, cur + 1, changed + (i == u ? 0: 1)))
				return true;
		}
		return false;
	}

    MagicDictionary() {
    	memset(trie, 0, sizeof(trie));
    	memset(count, 0, sizeof(count));
    }
    
    void buildDict(vector<string> dictionary) {
    	for(auto &s : dictionary) {
    		insert(s);
    	}
    }
    
    bool search(string searchWord) {
    	return searchP(0, searchWord, 0, 0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
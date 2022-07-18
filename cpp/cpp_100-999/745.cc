// C++
// leetcode 745
// https://leetcode.cn/problems/prefix-and-suffix-search/
// 用 node 的字典树

class WordFilter {
public:
	struct TrieNode
	{
		TrieNode *tns[26];
		vector<int> idxs;
		TrieNode() {
			for (int i = 0; i < 26; i++) {
				tns[i] = nullptr;
			}
		}
	};

	TrieNode *tr1, *tr2;

	void insert(string s, int tag, bool goodOrder) {
		int n = s.size();
		TrieNode *tr = (goodOrder ? tr1 : tr2);
		for (int i = (goodOrder ? 0 : n - 1); (goodOrder ? i < n : i >= 0); i += (goodOrder ? 1 : -1)) {
			int u = s[i] - 'a';
			if (tr->tns[u] == nullptr) {
				tr->tns[u] = new TrieNode();
			}
			tr = tr->tns[u];
			tr->idxs.push_back(tag);
		}
	}

	int query(string a, string b) {
		// pre
		TrieNode *p = tr1;
		for (int i = 0; i < a.size(); i++) {
			int u = a[i] - 'a';
			if(p->tns[u] == nullptr) {
				return -1;
			}
			p = p -> tns[u];
		}
		
		vector<int> &v1 = p -> idxs;
		p = tr2;
		for (int i = b.size() - 1; i >= 0; i--) {
			int u = b[i] - 'a';
			if(p->tns[u] == nullptr) {
				return -1;
			}
			p = p -> tns[u];
		}
		
		vector<int> &v2 = p -> idxs;
		for (int i = v1.size() - 1, j = v2.size() - 1; i >= 0 && j >= 0; ) {
			if (v1[i] == v2[j]) {
				return v1[i];
			} else if (v1[i] < v2[j]) {
				j--;
			} else {
				i--;
			}
		}
		return -1;
	}


    WordFilter(vector<string>& words) {
    	tr1 = new TrieNode();
    	tr2 = new TrieNode();
    	for(int i = 0; i < words.size(); i++) {
            // cout<<"insert one"<<endl;
    		insert(words[i], i, true);
    		insert(words[i], i, false);
    	}
    }
    
    int f(string pref, string suff) {
        // cout<<"try searching"<<endl;
    	return query(pref, suff);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
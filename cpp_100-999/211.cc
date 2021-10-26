// C++
// leetcode 211
// https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/


class WordDictionary {
public:
    const static int N = 40000;
    int idx = 0;
    int tr[N][26] = {0};
    bool isEnd[N] = {false};

    WordDictionary() {
    }
    
    void addWord(string word) {
        int p = 0;
        for(int i = 0; i< word.size(); i++) {
            int u = word[i] - 'a';
            if(tr[p][u] == 0)
                tr[p][u] = ++idx;
            p = tr[p][u];
        }
        isEnd[p] = true;
    }
    
    bool dfs(string& s, int sIdx, int trIdx) {

        // 结算
        if(sIdx == s.size())
            return  isEnd[trIdx];

        if(s[sIdx] == '.') {
            for(int i = 0; i < 26; i++) {
                if(tr[trIdx][i] != 0 && dfs(s, sIdx + 1, tr[trIdx][i]))
                    return  true;
            }
            return  false;
        } else {
            int u = s[sIdx] - 'a';
            if(tr[trIdx][u] == 0)
                return  false;
            return  dfs(s, sIdx + 1, tr[trIdx][u]);
        }
    }

    bool search(string word) {
        return  dfs(word, 0, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
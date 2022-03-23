// C++
// leetcode 472
// https://leetcode-cn.com/problems/concatenated-words/
// 字典树

class Solution {
public:
    int trie[100010][26];
    bool isEnd[100010];
    int idx = 0;

    void insert(string& s) {
        int p = 0;
        for (int i = 0; i < s.size(); i++) {
            int u = s[i] - 'a';
            if (trie[p][u] == 0) trie[p][u] = ++idx;
            p = trie[p][u];
        }
        isEnd[p] = true;
    }

    bool isGoodWord(string& s) {
        // cout<<"checking >> "<<s<<endl;
        return searchWithIndex(s, 0);
    }

    bool searchWithIndex(string& s, int done) {
        // cout<<"start IDX "<<string(done, '=')<<done<<endl;
        // if(set.find(s.substr(done)) != set.end()) return true;
        int p = 0;
        vector<int> next;
        for(int i = done; i < s.size(); ++i) {
            int u = s[i] - 'a';
            if(trie[p][u] == 0) {
                p = 0;
                break;
            }
            p = trie[p][u];
            if(isEnd[p]) next.push_back(i + 1);
        }
        if(isEnd[p] && done != 0) {
            // cout<<"endx IDX "<<string(done, '=')<<done<<endl;
            return true;
        }
        for(int i = next.size() - 1; i >= 0; --i) {
            if(searchWithIndex(s, next[i]))
                return true;
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        // 按字符串长度从小到大排序
        vector<string> res;
        sort(words.begin(),words.end(),[&](string &a,string &b)->bool{return a.size()<b.size();});
        // 预处理字符串数组，把每个字符串录入字典树
        memset(trie, 0, sizeof(trie));
        memset(isEnd, 0, sizeof(isEnd));
        for(auto &s : words) {
            if(s.size() == 0) {
                continue;
            }
            if(isGoodWord(s)) res.push_back(s);
            else insert(s);
        }
        return res;
    }
};
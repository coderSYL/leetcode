// C++
// leetcode 208
// https://leetcode-cn.com/problems/implement-trie-prefix-tree/
// 字典树

class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie* node = this;
        int size = word.size();
        for(int i = 0; i<size; i++){
        	if(node->next[word[i]-'a'] ==nullptr)
        		node->next[word[i]-'a'] =new Trie();
        	node = node->next[word[i]-'a'];
        }
        node->isEnd = true;
        // for (char c : word) {
        //     if (node->next[c-'a'] == NULL) {
        //         node->next[c-'a'] = new Trie();
        //     }
        //     node = node->next[c-'a'];
        // }
        // node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        int size = word.size();
        int i =0;
        while(i<size){
        	if(node->next[word[i]-'a'])
        		node = node->next[word[i++]-'a'];
        	else
        		break;
        }
        if(i == size && node->isEnd)
        	return true;
        return false;
        // for (char c : word) {
        //     node = node->next[c - 'a'];
        //     if (node == NULL) {
        //         return false;
        //     }
        // }
        // return node->isEnd;
    }
    

    bool startsWith(string prefix) {
        Trie* node = this;
        int size = prefix.size();
        int i =0;
        while(i<size){
        	if(node->next[prefix[i]-'a'])
        		node = node->next[prefix[i++]-'a'];
        	else
        		break;
        }
        if(i == size)
        	return true;
        return false;
        // for (char c : prefix) {
        //     node = node->next[c-'a'];
        //     if (node == NULL) {
        //         return false;
        //     }
        // }
        // return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
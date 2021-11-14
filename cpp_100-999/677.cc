// C++
// leetcode 677
// https://leetcode-cn.com/problems/map-sum-pairs/

class MapSum {
private:
	int trie[2520][26];
	int val_[2520];
	int idx;
	int sum_;
public:
    MapSum() {
    	memset(val_, 0, sizeof(val_));
    	memset(trie, 0, sizeof(trie));
    	idx = 0;
    }
    
    void insert(string key, int val) {
    	int p = 0;
    	for(int i = 0; i < key.size(); i++) {
    		int u = key[i] - 'a';
    		if(trie[p][u] == 0)
    			trie[p][u] = ++idx;
    		p = trie[p][u];
    	}
    	val_[p] = val;
    }
    
    int sum(string prefix) {
    	sum_ = 0;
    	int p = 0;
    	for(int i = 0; i < prefix.size(); i++) {
    		int u = prefix[i] - 'a';
    		if(trie[p][u] == 0)
    			return	0;
    		p = trie[p][u];
    	}
    	dfs(p);
    	return	sum_;
    }

    void dfs(int m) {
    	sum_ += val_[m];
    	if(m == 0)	return;
    	for(int i = 0; i < 26; i++)
    		dfs(trie[m][i]);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
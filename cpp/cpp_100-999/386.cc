// C++
// leetcode 386
// https://leetcode-cn.com/problems/lexicographical-numbers/

class Solution {
public:
	int idx = 0;
	int n;
	vector<int> res;
	void dfs(int cur) {
		if(cur <= n)
			res[idx++] = cur;
		else
			return;
		for(int i = 0; i < 10; i++) {
			dfs(cur * 10 + i);
		}
	}

    vector<int> lexicalOrder(int n_) {
    	n = n_;
    	res.resize(n);
    	for(int i = 1; i < 10; i++) {
    		if(i <= n_)
    			dfs(i);
    	}
    	return res;
    }
};
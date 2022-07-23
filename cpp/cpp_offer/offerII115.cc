// C++
// leetcode offerII 115
// https://leetcode.cn/problems/ur2n8P/

class Solution {
public:
	int he[10009], e[10009], ne[10009], in[10009];
	int idx = 0;

	void add(int a, int b) {
		e[idx] = b;
		ne[idx] = he[a];
		he[a] = idx++;
		in[b]++;
	}

	void initMap() {
		memset(he, -1, sizeof(he));
		memset(in, 0, sizeof(in));
		idx = 0;
	}

    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
    	initMap();
    	
    	int n = nums.size();

    	for(auto &se : sequences) {
    		for(int i = 1; i < se.size(); i++) {
    			add(se[i - 1], se[i]);
    		}
    	}

    	queue<int> q;
    	for (int i = 1; i <= n; i++) {
    		if (in[i] == 0)
    			q.push(i);
    	}

    	int loc = 0;
    	while(!q.empty()) {
    		if(q.size() != 1)
    			return false;

    		int t = q.front();
    		if (nums[loc++] != t)
    			return false;
    		q.pop();

    		for(int i = he[t]; i != -1; i = ne[i]) {
    			int j = e[i];
    			if (--in[j] == 0) {
    				q.push(j);
    			}
    		}
    	}
    	return true;
    }
};
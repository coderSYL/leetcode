// C++
// leetcode 792
// https://leetcode.cn/problems/number-of-matching-subsequences/

class Solution {
public:
	vector<int> a[26];

	void init(string &s) {
		for(int i = 0; i < 26; i++) {
			a[i] = vector<int>{};
		}
		for(int i = 0; i < s.size(); i++) {
			int u = s[i] - 'a';
			a[u].push_back(i);
			// cout<<u<<" in : "<<i<<endl;
		}
		return;
	}

	int getP(char c, int now) {
		// cout<<"try to find "<<c<<" from Index "<<now<<endl;
		int u = c - 'a';
		int l = 0, r = a[u].size() - 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(a[u][mid] <= now)
				l = mid + 1;
			else
				r = mid - 1;
		}
		if (l == a[u].size())
			return -2;
		// cout<<"Found in "<<a[u][l]<<endl;
		return a[u][l];
	}

    int numMatchingSubseq(string s, vector<string>& words) {
    	init(s);
    	int res = 0;
    	for(auto &word : words) {
    		int p = -1;
    		bool good = true;
    		for(int i = 0; i < word.size(); i++) {
    			p = getP(word[i], p);
    			if(p == -2) {
    				good = false;
    				break;
    			}
    		}
    		if(good)
    			res++;
    	}
    	return res;
    }
};
// C++
// leetcode 140
// https://leetcode-cn.com/problems/word-break-ii/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    	vector<vector<string>>	f;
    	f.push_back(vector<string>{""});
    	set<string>	set(wordDict.begin(), wordDict.end());
    	for(int i = 0; i < s.size(); i++) {
    		vector<string>	tmp;
    		for(int j = 0; j <= i; j++) {
    			string a = s.substr(j, i - j + 1);
    			if(f[j].size() != 0 && set.find(a) != set.end()) {
    				// 存在，可以加入tmp
    				if(j == 0) {
    					for(auto x : f[j]) {
    						tmp.push_back(a);
    					}
    				} else {
    					for(auto x : f[j]) {
    						tmp.push_back(x + " " + a);
    					}
    				}
    			}
    		}
    		f.push_back(tmp);
    	}
    	return	f[s.size()];
    }
};
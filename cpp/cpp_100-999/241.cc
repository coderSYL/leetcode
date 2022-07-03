// C++
// leetcode 241
// https://leetcode.cn/problems/different-ways-to-add-parentheses/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
    	return dfs(expression, 0, expression.size() - 1);
    }

    vector<int> dfs(string &s, int l, int r) {
    	vector<int> res;
    	for(int i = l; i <= r; i++) {
    		if(isNumChar(s[i]))
    			continue;
    		vector<int> left = dfs(s, l, i-1);
    		vector<int> right = dfs(s, i + 1, r);
    		for(auto x: left) {
    			for(auto y : right) {
    				if(s[i] == '+') {
    					res.push_back(x+y);
    				} else if (s[i] == '-'){
    					res.push_back(x-y);
    				} else {
    					res.push_back(x*y);
    				}
    			}
    		}
    	}
    	if (res.empty()) {
    		res.push_back(stoi(s.substr(l, r-l+1)));
    	}
    	return res;
    }

    bool isNumChar(char c) {
    	if(c >= '0' && c <= '9')
    		return true;
    	return false;
    }
};
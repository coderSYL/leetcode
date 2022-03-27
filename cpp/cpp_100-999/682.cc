// C++
// leetcode 682 
// https://leetcode-cn.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
    	int n = ops.size();
    	vector<int> tmp;
    	for(int i = 0; i < n; i++) {
    		int cur = 0;
    		if(ops[i] == "D") {
    			cur = 2 * tmp.back();
    			tmp.push_back(cur);
    		} else if(ops[i] == "+") {
    			cur = tmp.back() + tmp[tmp.size() - 2];
    			tmp.push_back(cur);
    		} else if(ops[i] == "C") {
    			tmp.pop_back();
    		} else {
    			cur = stoi(ops[i]);
    			tmp.push_back(cur);
    		}
    	}

    	int res = 0;
    	for(auto & x : tmp)
    		res += x;
    	return res;
    }
};
// C++
// leetcode 1282
// https://leetcode.cn/problems/group-the-people-given-the-group-size-they-belong-to/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    	map<int, vector<int>> m;
    	int n = groupSizes.size();
    	for (int i = 0; i < n; i++) {
    		m[groupSizes[i]].push_back(i);
    	}

    	vector<vector<int>> res;

    	for (auto &[k, v] : m) {
    		vector<int> tmp;
    		for (int i = 0; i < v.size(); i++) {
    			tmp.push_back(v[i]);
    			if (tmp.size() == k) {
    				res.push_back(tmp);
    				tmp.clear();
    			}
    		}
    	}

    	return res;
    }
};
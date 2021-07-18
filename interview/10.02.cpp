// C++
// leetcode 面试题 10.02
// https://leetcode-cn.com/problems/group-anagrams-lcci/
// 

class Solution {
public:
	static bool cmp(int a, int b) {
		return a > b;
	}

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	map<string, vector<string>>	temp;
    	for(auto& s : strs) {
    		int size_s = s.size();
    		string ss = s;
    		sort(ss.begin(), ss.end());
    		auto it = temp.find(ss);
    		if(it == temp.end()) {
    			// 不存在
    			temp[ss] = vector<string>{s};
    		} else {
    			temp[ss].push_back(s);
    		}
    	}
    	vector<vector<string>> res;
    	auto it = temp.begin();
    	while(it != temp.end()) {
    		res.push_back(it -> second);
    		++it;
    	}
    	return	res;
    }
};
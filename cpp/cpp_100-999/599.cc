// C++
// leetcode 599
// https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    	int n1 = list1.size(), n2 = list2.size();
    	unordered_map<string, int> getIndex;
    	vector<string> res;
    	int sumNow = INT_MAX;
    	for(int i = 0; i < n1; i++) {
    		getIndex[list1[i]] = i;
    	}
    	for(int i = 0; i < n2; i++) {
    		// 如果不存在
    		if(getIndex.find(list2[i]) == getIndex.end())
    			continue;
    		int cur = i + getIndex[list2[i]];
    		if(cur > sumNow)
    			continue;
    		else if(cur == sumNow)
    			res.push_back(list2[i]);
    		else {
    			sumNow = cur;
    			res.clear();
    			res.push_back(list2[i]);
    		}
    	}
    	return res;
    }
};
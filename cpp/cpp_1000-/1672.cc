// C++
// leetcode 1672
// https://leetcode-cn.com/problems/richest-customer-wealth/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
    	int res = 0;
    	for(auto &person : accounts) {
    		int tmp = 0;
    		for(auto & x : person)
    			tmp += x;
    		res = max(res, tmp);
    	}
    	return res;
    }
};
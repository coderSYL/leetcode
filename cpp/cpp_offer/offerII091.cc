// C++
// leetcode offerII 091
// https://leetcode.cn/problems/JEj789/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
    	int n = costs.size(), res = INT_MAX;
    	for (int i = 1; i < n; i++) {
    		for(int j = 0; j < 3; j++) {
    			int cur = INT_MAX;
    			for(int k = 0; k < 3; k++) {
    				if (j == k)
    					continue;
    				cur = min(cur, costs[i][j] + costs[i-1][k]);
    			}
    			costs[i][j] = cur;
    		}
    	}
    	for(int i = 0; i < 3; i++) {
	    	res = min(res, costs[n-1][i]);
	    }
	    return res;
    }	
};
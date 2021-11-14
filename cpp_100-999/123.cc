// C++
// leetcode 123
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int m1 = INT_MIN;
    	int m2 = INT_MIN;
    	int m3 = INT_MIN;
    	int m4 = 0;
    	for(auto &x : prices) {
    		m1 = max(m1, -x);
    		m2 = max(m2, m1 + x);
    		m3 = max(m3, m2 - x);
    		m4 = max(m4, m3 + x);
    	}
    	return	m4;
    }
};
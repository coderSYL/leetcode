// C++
// leetcode 122
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
// 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int pre = prices[0];
    	int nMinusOne = prices.size() - 1;
    	int res = 0;
    	for(int i = 1; i < prices.size(); i++) {
    		if(prices[i] > pre)
    			res += prices[i] - pre;
    		pre = prices[i];
    	}
    	return	res;
    }
};
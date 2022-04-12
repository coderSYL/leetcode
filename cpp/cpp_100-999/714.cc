// C++
// leetcode 714
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    	int buy = INT_MIN, sell = 0;
    	for(auto &x : prices) {
    		buy = max(buy, sell - x);
    		sell = max(sell, buy + x - fee);
    	}
    	return sell;
    }
};
// C++
// leetcode 188
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    	vector<int> buy(k+1, INT_MIN);
    	vector<int> sell(k+1, 0);
    	int n = prices.size();
    	buy[0] = 0;
    	for(auto& price : prices) {
    		for(int i = 1; i <= k; i++) {
    			if(buy[i] == INT_MIN)
    				break;
    			sell[i] = max(sell[i], buy[i] + price); 
    		}
    		for(int i = 1; i <= k ; i++) {
    			buy[i] = max(buy[i], sell[i-1] - price);
    		}
    	}
    	return sell[k];
    }
};
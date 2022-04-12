// C++
// leetcode 309
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int buy = INT_MIN;
    	int sell = 0;
    	int secondSell = 0;
    	bool cooling = false;
    	for(auto & x: prices) {
    		if(!cooling) {
    			buy = max(buy, sell - x);
    		} else {
    			buy = max(buy, secondSell - x);
    		}
    		if(buy + x > sell) {
    			secondSell = sell;
    			sell = buy + x;
    			cooling = true;
    		} else
    			cooling = false;
    	}
    	return sell;
    }
};
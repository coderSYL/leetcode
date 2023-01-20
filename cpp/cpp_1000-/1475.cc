// C++
// leetcode 1475
// https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    	int n = prices.size();
    	vector<int> res(n);

    	for (int i = n - 1; i >= 0; i--) {
    		int x = prices[i], j = i;

    		while (++j < n) {
                if (prices[j] <= x)
                    break;
            }
            
    		if (j == n) {
    			res[i] = x;
    		} else {
    			res[i] = x - prices[j];
    		}
    	}

    	return res;
    }
};
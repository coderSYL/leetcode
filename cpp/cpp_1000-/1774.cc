// C++
// leetcode 1774
// https://leetcode.cn/problems/closest-dessert-cost/

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
    	int lim = 15000;
    	bool ok[lim+1];
    	memset(ok, 0, sizeof(ok));

    	for (auto base : baseCosts) {
    		if (base <= lim) {
    			ok[base] = true;
    		}
    	}

    	for (auto t : toppingCosts) {
    		for (int i = lim; i >= 0; i--) {
    			if (ok[i]) {
    				if (t + i <= lim) {
    					ok[i + t] = true;
    				}
    				if (2 * t + i <= lim) {
    					ok[2 * t + i] = true;
    				}
    			}
    		}
    	}

    	for (int i = 0; i <= target; i++) {
    		if (ok[target - i])
    			return target - i;
    		if (ok[target + i])
    			return target + i;
    	}
    	for (int i =  2 * target + 1; i <=lim; i++) {
    		if(ok[i])
    			return i;
    	}
    	return -1;
    }
};
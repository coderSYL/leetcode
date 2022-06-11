// C++
// leetcode 875
// https://leetcode.cn/problems/koko-eating-bananas/

class Solution {
public:
	int get_h(vector<int>& piles, int speed) {
		int res = 0;
		for(auto &x : piles) {
			res += (x / speed) + (x % speed == 0 ? 0 : 1);
		}
		return res;
	}

    int minEatingSpeed(vector<int>& piles, int h) {
    	int max_bananas = 0;
    	for(auto &x : piles)
    		max_bananas = max(max_bananas, x);
    	int l = 1, r = max_bananas;
    	while(l <= r) {
    		// l always ok
    		// cout<<l<<", "<<r<<endl;
    		int mid = (l + r + 1) / 2;
    		if(get_h(piles, mid) <= h) {
    			r = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	return l;
    }
};
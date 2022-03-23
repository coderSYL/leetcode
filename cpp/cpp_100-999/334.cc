// C++
// leetcode 334
// https://leetcode-cn.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	long n1 = LONG_MIN, n2 = n1;
    	for(auto & x : nums) {
    		if(n2 != LONG_MIN && x > n2)
    			return true;
    		if(n1 != LONG_MIN && x > n1 && (n2 == LONG_MIN || x < n2))
    			n2 = x;
    		if(n1 == LONG_MIN || x < n1)
    			n1 = x;
    	}
    	return false;
    }
};
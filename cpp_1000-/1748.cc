// C++
// leetcode 1748
// https://leetcode-cn.com/problems/sum-of-unique-elements/

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
    	map<int, int> cnt;
    	int res = 0;
    	for(auto & x : nums) cnt[x]++;
    	for(auto &[k, v] : cnt) {
    		if(v == 1) res += k;
    	}
    	return res;
    }
};
// C++
// leetcode 217
// https://leetcode-cn.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	unordered_map<int, int> m;
    	for(auto & x : nums) {
    		m[x]++;
    		if(m[x] > 1) return true;
    	}
    	return false;
    }
};
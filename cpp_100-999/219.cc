// C++
// leetcode 219
// https://leetcode-cn.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	int n = nums.size();
    	unordered_set<int> s;
    	for(int i = 0; i < n; ++i) {
    		if(s.find(nums[i]) == s.end()) {
    			// 不存在，则插入
    			s.insert(nums[i]);
    		} else {
    			// 存在，返回true
    			return true;
    		}
    		if(s.size() == k + 1) {
    			s.erase(nums[i - k]);
    		}
    	}
    	return false;
    }
};
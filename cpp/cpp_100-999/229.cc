// C++
// leetcode 229
// https://leetcode-cn.com/problems/majority-element-ii/
// 


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	// 统计
    	unordered_map<int, int>	m;
    	for(auto x : nums) {
    		m[x]++;
    	}

    	vector<int>	res;
    	int target  = nums.size() / 3;
    	for(auto [num, cnt] : m) {
    		if(cnt > target)
    			res.push_back(num);
    	}

    	return	res;
    }
};
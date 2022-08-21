// C++
// leetcode 448
// https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	int n = nums.size();
    	int cnt[n + 1];
    	memset(cnt, 0, sizeof(cnt));
    	for (auto x : nums) {
    		cnt[x]++;
    	}
    	vector<int> res;
    	for (int i = 1; i <= n; i++) {
    		if (cnt[i] == 0)
    			res.push_back(i);
    	}
    	return res;
    }
};
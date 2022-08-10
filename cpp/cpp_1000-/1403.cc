// C++
// leetcode 1403
// https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order/

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
    	priority_queue<int> pq(nums.begin(), nums.end());

    	int sum = 0;
    	for(auto x : nums)
    		sum += x;

    	int cur = 0;
    	vector<int> res;
    	while (cur * 2 <= sum) {
    		cur += pq.top();
    		res.push_back(pq.top());
    		pq.pop();
    	}

    	return res;
    }
};
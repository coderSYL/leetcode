// C++
// leetcode 78
// https://leetcode-cn.com/problems/subsets/
// 递归

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	int n = nums.size();
    	if(n == 0)
    		return	vector<vector<int>>(1,vector<int>(0));
    	queue<vector<int>>	q;
    	int back = nums.back();
    	nums.pop_back();
    	vector<vector<int>> res = subsets(nums);
    	for(auto v : res) {
    		v.push_back(back);
    		q.push(v);
    	} 
    	while(!q.empty()) {
    		res.push_back( q.front() );
    		q.pop();
    	}
    	return	res;
    }
};
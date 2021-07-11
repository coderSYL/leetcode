// C++
// leetcode 
// https://leetcode-cn.com/contest/weekly-contest-249/problems/concatenation-of-array/
// 周赛1

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> res(2 * n);
    	for(int i = 0; i < n; ++i) {
    		res[i] = nums[i];
    		res[i + n] = res[i];
    	}
    	return res;
    }
};
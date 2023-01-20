// C++
// leetcode 775
// https://leetcode.cn/problems/global-and-local-inversions/

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int m = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
        	if (m < nums[i])
        		return false;
        	m = min(m, nums[i+1]);
        }
        return true;
    }
};
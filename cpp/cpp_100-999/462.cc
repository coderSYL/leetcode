// C++
// leetcode 462 
// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int n = nums.size();
    	int good_num = nums[n/2];
    	if(n & 1 == 0)
    		good_num = (good_num + nums[n/2-1]) / 2;
    	int res = 0;
    	for(int i = 0; i < n ; ++i) {
    		res += abs(good_num - nums[i]);
    	}
    	return res;
    }
};
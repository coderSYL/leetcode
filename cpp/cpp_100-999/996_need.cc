// C++
// leetcode 996
// https://leetcode-cn.com/problems/number-of-squareful-arrays/

class Solution {
public:
	unorder_set<int> s;
	bool isGood(int a) {
		int l = 1, r = min(a, 2 * 46340 - 1);
		while(l <= r) {
			int mid = (l + r) >>1;
			if(mid * mid == a)
				return true;
			else if(mid * mid < a)
				l = mid + 1;
			else
				r = mid - 1;

		}
		return false;
	}
    int numSquarefulPerms(vector<int>& nums) {
    	int n = nums.size() -1, res =0;
    	for(int i = 0; i < n; i++) {
    		if(s.count(nums[i]) == 1)
    			continue;
    		if(isGood(nums[i] + nums[i+1] ))
    			res++;
    	}
    	return res;
    }
};
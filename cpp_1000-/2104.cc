// C++
// leetcode 2104
// https://leetcode-cn.com/problems/sum-of-subarray-ranges/
// 拙劣的双循环

class Solution {
public:
	using ll = long long;
    long long subArrayRanges(vector<int>& nums) {
        ll res = 0;
        int maxi, mini, n = nums.size();
        for(int i = 0; i < n; i++) {\
        	maxi = nums[i], mini = nums[i];
        	for(int j = i + 1; j < n; j++) {
        		maxi = max(maxi, nums[j]);
        		mini = min(mini, nums[j]);
        		res += maxi - mini;
        	}
        }
        return res;
    }
};
// C++
// leetcode 719
// https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
    	sort(nums.begin(), nums.end());
    	int n = nums.size();
    	int l = 0, r = nums[n-1] - nums[0], mid = 0, cnt = 0;
    	while(l < r) {
    		mid = (l + r) >> 1;
    		cnt = 0;
    		for(int i = 0, j = 0; i < n; i++) {
    			while(j < n && nums[j] - nums[i] <= mid)
    				j++;
    			cnt +=  j - i - 1;
    		}
    		if(cnt >= k) {
    			r = mid;
    		} else {
    			l = mid + 1;
    		}
    	}
    	return r;
    }
};
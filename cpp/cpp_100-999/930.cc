// C++
// leetcode 930
// https://leetcode-cn.com/problems/binary-subarrays-with-sum/
// 不知道叫啥，干就完了

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    	int n = nums.size();
    	int count[n + 1];
        memset(count, 0, sizeof(count));
    	count[0] = 1;
    	int now =0;
    	for(int i = 0; i < n; ++i) {
    		now += nums[i];
    		++count[now];
    	}

  		int res = 0;
  		for(int i = now; i >= goal; --i) {
  			if(goal == 0)
  				res += count[i] * (count[i] - 1) / 2;
  			else
  				res += count[i] * count[i - goal];
  		}
  		return res;
    }
};
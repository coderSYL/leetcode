// C++
// leetcode 992
// https://leetcode-cn.com/problems/subarrays-with-k-different-integers/
// 有点屑的方法呜呜呜
// 由于nums[i]的值有范围，可以把用于计数的map改为数组，改后效率大增，芜湖！

class Solution {
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		int type = 0, n = nums.size(), res = 0;
		int m[n+1];
		memset(m, 0, sizeof(m));
		int l = 0, r = 0;
		// 初始化
		while (r < n && type < k) {
			if (++m[nums[r++]] == 1) type++;
		}
		if (type < k) return 0;

		while (r <= n) {
			// 以r)为结尾的
			while (type > k && l < r) {
				if (--m[nums[l++]] == 0) {
					type--;
				}
			}
			int possibleLForTheR = l;
			// cout<<"["<<l<<", "<<r<<"]"<<endl;
			while (true) {
				res++;
				if (--m[nums[possibleLForTheR++]] == 0) break;
			}
			// cout<<possibleLForTheR-l<<endl;
			while (possibleLForTheR != l) {
				m[nums[--possibleLForTheR]]++;
			}
            if(r == n) break;
			if(++m[nums[r]] == 1) type++;
			r++;
		}
		return res;
	}
};
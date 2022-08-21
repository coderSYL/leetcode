// C++
// leetcode 697
// https://leetcode.cn/problems/degree-of-an-array/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
    	int n = nums.size();
    	int cnt[50009], first[50009], last[50009];
    	memset(cnt, 0, sizeof(cnt));
    	memset(first, -1, sizeof(first));
    	memset(last, -1, sizeof(last));
    	int mx = 0, tmp, x;
    	vector<int> arr;
    	for (int i = 0; i < n; i++) {
    		x = nums[i];
    		tmp = ++cnt[x];
    		if (tmp == 1) {
    			first[x] = i;
    		}
    		if (tmp > mx) {
    			arr.clear();
    			arr.push_back(x);
    			mx = tmp;
    		} else if (tmp == mx) {
    			arr.push_back(x);
    		}
    		last[x] = i;
    	}
    	int res = 99999;
    	for (auto i : arr) {
    		res = min(res, last[i] - first[i] + 1);
    	}
    	return res;
    }
};
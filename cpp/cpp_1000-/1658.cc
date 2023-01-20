// C++
// leetcode 1658
// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/

class Solution {
public:
	int findIdx(vector<int>& arr, int t) {
		int n = arr.size();
		if (t < 0 || t > arr[0])
			return -1;	// not found

		int l = 0, r = n - 1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if (arr[mid] == t)
				return mid;
			else if (arr[mid] < t)
				r = mid - 1;
			else
				l = mid + 1;
		}

		return -1;
	}

    int minOperations(vector<int>& nums, int x) {
    	int n = nums.size();
    	vector<int> sum(n + 1, 0);
    	vector<int> revSum(n + 1, 0);
    	for (int i = 0; i < n; i++) {
    		sum[i + 1] = sum[i] + nums[i];
    		revSum[n - i - 1] = revSum[n - i] + nums[n - 1 - i];
    	}

    	if (x > sum[n]) // check if x is too big
    		return -1;
    	else if (x == sum[n])
    		return n;

    	int res = INT_MAX;
    	for (int i = 0 ; sum[i] <= x && i <= n; i++) {
    		int need = x - sum[i];int idx = findIdx(revSum, need);
    		if (idx == -1)
    			continue;
    		int cur = i + n - idx;
    		res = min(cur, res);
    	}
    	return (res == INT_MAX ? -1 : res);
    }
};
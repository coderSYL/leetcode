// C++
// leetcode 6160
// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    	// 将 nums 数组排序
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = queries.size();

        // nums 数组的前缀和
        vector<int> sum(n, nums[0]);
        for (int i = 1; i < n; i++)
        	sum[i] = sum[i - 1] + nums[i];

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
        	// 二分
        	int l = 0, r = n - 1, x = queries[i];
        	while (l <= r) {
        		int mid = (l + r) / 2;
        		if (sum[mid] <= x) {
        			l = mid + 1;
        		} else {
        			r = mid - 1;
        		}
        	}
        	res[i] = l;
        }
        return res;
    }
};
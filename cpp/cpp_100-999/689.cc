// C++
// leetcode 689
// https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    	int n = nums.size();
    	vector<int>	res(3, 10000);
    	int res_sum = 0, cur = 0;
    	for(int i = 0; i < n; i++) {
    		if(i < k - 1) {
    			cur += nums[i];
    			continue;
    		}
    		cur += nums[i];
    		swap(nums[i - k + 1], cur);
    		cur = nums[i - k + 1] - cur;
    	}
    	for(int i = n - k + 1; i < n; i++)
    		nums[i] = 0;
    	cur = 0;
    	// 至此，nums[i] 已经全部变成第 i 位为起点的 k 长度数组和

    	vector<int> l(n);
    	vector<int> lIdx(n);
    	vector<int> r(n);
    	vector<int> rIdx(n);
    	l[0] = nums[0];
    	lIdx[0] = 0;
    	for(int i = 1; i < n; i++) {
    		if(nums[i] > l[i - 1]) {
    			lIdx[i] = i;
    			l[i] = nums[i];
    		} else {
    			lIdx[i] = lIdx[i - 1];
    			l[i] = l[i - 1];
    		}
    	}
    	r[n - 1] = nums[n - 1];
    	rIdx[n - 1] = n - 1;
    	for(int i = n - 2; i >= 0; i--) {
    		if(nums[i] >= r[i + 1]) {
    			r[i] = nums[i];
    			rIdx[i] = i;
    		} else {
    			r[i] = r[i + 1];
    			rIdx[i] = rIdx[i + 1];
    		}
    	}

    	// 然后以中间点的数组的起始点为枢纽，做一遍遍历
    	// 为了给左右两边的数组留够长度，遍历范围选为[k, n - 2k]
    	for(int i = k; i <= n - 2*k; i++) {
    		cur = nums[i] + l[i - k] + r[i + k];
    		if(cur == res_sum) {
    			// 和的大小相同，比字典序
    			if(lIdx[i - k] < res[0]) {
    				// 替换答案
    				res[0] = lIdx[i - k];
    				res[1] = i;
    				res[2] = rIdx[i + k];
    			}
    		} else if(cur > res_sum) {
    			// 和更大，直接替换
    			res[0] = lIdx[i - k];
				res[1] = i;
				res[2] = rIdx[i + k];
				res_sum = cur;
    		}
    	}
    	return res;
    }
};


// // 方法二：
// // 宫水三叶的dp方法，用时较长，但是解法具有普遍意义
// class Solution {
// public:
//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         long sum[n + 1];
//         sum[0] = 0;
//         for(int i = 1; i <= n; i++)
//             sum[i] = sum[i - 1] + nums[i - 1];
//         vector<vector<long>> f(n + 10, vector<long>(4, 0));
//         for(int i = n - k + 1; i > 0; --i) {
//             for(int j = 1; j < 4; j++) {
//                 f[i][j] = max(f[i + 1][j], f[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]);
//             }
//         }
//         vector<int> res(3);
//         int i = 1, j = 3, idx = 0;
//         while(j > 0) {
//             if (f[i + 1][j] > f[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]) {
//                 i++;
//             } else {
//                 res[idx++] = i - 1;
//                 i += k; j--;
//             }
//         }
//         return res;
//     }
// };
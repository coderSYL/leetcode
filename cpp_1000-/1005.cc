// C++
// leetcode 1005
// https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    	int cnt[201] = {0};
    	int sum = 0;
    	// 统计sum，处理cnt数字
    	for(auto x : nums) {
    		sum += x;
    		++cnt[x + 100];
    	}
    	// 从 -100 到 -1的顺序，在有机会的情况下翻转
    	int idx = -100;
    	while(k > 0 && idx < 0) {
    		int good = min(k, cnt[idx+100]);
    		if(good != 0) {
    			k -= good;
    			cnt[idx + 100] -= good;
    			cnt[-idx + 100] += good;
    			sum -= 2 * good * idx;
    		}
    		idx++;
    	}
    	// 如果还剩下奇数次，则必须将一个非负数翻转
    	if(k % 2 == 1) {
    		int minVal = 0;
    		while(cnt[minVal + 100] == 0)
    			++minVal;
    		sum -= 2 * minVal;
    	}
    	
    	return sum;
    }
};

// 利用 lambda 与优先队列，效率略低
// class Solution {
// public:
//     int largestSumAfterKNegations(vector<int>& nums, int k) {
//         int minVal = 101;
//         auto cmp = [nums](int a, int b){return nums[a] > nums[b];};
//         bool zero = false;
//         priority_queue<int, vector<int>, decltype(cmp) > q(cmp);
//         for(int i = 0; i < nums.size(); ++i) {
//             if(nums[i] < 0) {
//                 q.push(i);
//             } else if(nums[i] == 0) {
//                 zero = true;
//             }
//             if(!zero) {
//                 minVal = min(minVal, (nums[i] > 0 ? nums[i] : -nums[i]));
//             }
//         }
//         int sum = 0;
//         if(k <= q.size()) {
//             // 不能全部变正
//             while(k--) {
//                 nums[q.top()] = -nums[q.top()];
//                 q.pop();
//             }
//         } else {
//             k -= q.size();
//             while(!q.empty()) {
//                 nums[q.top()] = -nums[q.top()];
//                 q.pop();
//             }
//             if(!zero && k%2)
//                 sum -= 2 * minVal;
//         }
//         for(auto x : nums)
//             sum += x;
//         return sum;
//     }
// };
// C++
// leetcode 532
// https://leetcode.cn/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    	map<int, int> state;
    	// 0 for exist
    	// 0b1 for (x, x-k) exist
    	// 0b10 for (x, x+k) exist
    	int res = 0;
    	if(k == 0) {
    		for(auto &x : nums) {
    			state[x]++;
    			if(state[x] == 2)
    				res++;
    		}
    		return res;
    	}
    	for(auto &x : nums) {
    		int t1 = x - k, t2 = x + k;
    		int cur = 0;
    		if(state.find(t1) != state.end()) {
    			// (x-k, x)
    			cur = 0b1;
    			if((state[t1] & 0b10) == 0) {
    				res++;
    				state[t1] |= 0b10;
    			}
    		}
    		if(state.find(t2) != state.end()) {
    			// (x+k, x)
    			cur |= 0b10;
    			if((state[t2] & 0b1) == 0) {
    				res++;
    				state[t2] |= 0b1;
    			}
    		}
    		state[x] |= cur;
    	}
    	return res;
    }
};

// // 方法二，排序后双指针
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//     	int res = 0, n = nums.size();
//         if(k == 0) {
//             map<int, int> state;
//     		for(auto &x : nums) {
//     			state[x]++;
//     			if(state[x] == 2)
//     				res++;
//     		}
//     		return res;
//     	}
//     	sort(nums.begin(), nums.end());
//         for(int i = 0, j = 0; j < n; i++) {
//             while(j < n && nums[j] - nums[i] < k)
//                 j++;
//             if(j != n && nums[j] == nums[i] + k)
//                 res++;
//             while(i+1<n && nums[i] == nums[i+1])
//                 i++;
//         }
//     	return res;
//     }
// };
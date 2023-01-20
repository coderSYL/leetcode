// C++
// leetcode 2293
// https://leetcode.cn/problems/min-max-game/

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
    	int n = nums.size(), cur_size = n;

    	// 滚动数组
        vector<int> arr(n);
        while(cur_size != 1) {
        	int next_size = cur_size / 2;
        	for (int i = 0; i < next_size; i++) {
        		int a = 2 * i, b = a + 1;
        		if (b == cur_size)
        			b--;
        		if (i % 2 == 0) {
        			arr[i] = min(nums[a], nums[b]);
        		} else {
        			arr[i] = max(nums[a], nums[b]);
        		}
        	}
        	cur_size = next_size;
        	nums.swap(arr);
        }
        
        return nums[0];
    }
};
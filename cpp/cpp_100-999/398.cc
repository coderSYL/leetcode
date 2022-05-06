// C++
// leetcode 398
// https://leetcode-cn.com/problems/random-pick-index/

class Solution {
public:
	map<int, vector<int>> m;
    Solution(vector<int>& nums) {
    	int n = nums.size();
    	for(int i = 0; i < n; i++) {
    		m[nums[i]].push_back(i);
    	}
    }
    
    int pick(int target) {
    	vector<int> &tmp = m[target];
    	int n = tmp.size();
    	return tmp[rand()%n];
    }
};

// 方法二
// class Solution {
// public:
//     vector<int> nums_;
//     int n;
//     Solution(vector<int>& nums) {
//         n = nums.size();
//         nums_.swap(nums);
//     }
    
//     int pick(int target) {
//         int cnt = 0;
//         for(int i = 0; i < n; i++) {
//             if(nums_[i] == target)
//                 cnt++;
//         }
//         int idx = rand()%cnt;
//         cnt = 0;
//         for(int i = 0; i < n; i++) {
//             if(nums_[i] == target) {
//                 if(idx == cnt) {
//                     return i;
//                 }
//                 cnt++;
//             }
//         }
//         return -1;
//     }
// };
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
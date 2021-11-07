// C++
// leetcode 268
// https://leetcode-cn.com/problems/missing-number/
// 求和 或者 异或


class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int sum = nums.size() * (nums.size() + 1) / 2;
    	for(auto x : nums)
    		sum -= x;
    	return	sum;
    }
};


// // 方法二：异或
// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//     	int res = nums.size();
//         for(int i = 0; i < nums.size(); i++) {
//             res ^= nums[i];
//             res ^= i;
//         }
//     	return	res;
//     }
// };
// C++
// leetcode 561
// https://leetcode-cn.com/problems/array-partition-i/
// 排序，贪心

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int i = 0;
        int n = nums.size();
        while(i < n) {
            res += nums[i];
            i += 2;
        }
        return res;
    }
};
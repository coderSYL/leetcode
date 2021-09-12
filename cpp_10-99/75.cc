// C++
// leetcode 75
// https://leetcode-cn.com/problems/sort-colors/
// 一遍循环，0调到左边，2调到右边

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int next0 = 0, next2 = n - 1;
        int p = 0;
        while(p <= next2) {
            if(nums[p] == 0) {
                if(p == next0) {
                    p++;
                    next0++;
                } else {
                    swap(nums[p], nums[next0]);
                    next0++;
                }
            } else if(nums[p] == 1) {
                p++;
            } else {
                // 等于2
                swap(nums[p], nums[next2]);
                next2--;
            }
        }
        return;
    }
};
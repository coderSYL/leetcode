// C++
// leetcode 31
// https://leetcode-cn.com/problems/next-permutation/
// 模拟，偷三叶的方法

class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while(l < r) {
            swap( nums[l], nums[r]);
            ++l;
            --r;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p = n - 1;
        while(p >= 1 && nums[p - 1] >= nums[p])
            --p;
        if(p == 0) {
            reverse(nums, 0, n - 1);
            return;
        } else {
            int q = p;
            while(q + 1 < n && nums[q + 1] > nums[p - 1])
                ++q;
            swap(nums[p - 1], nums[q]);
            reverse(nums, p, n - 1);
        }
    }
};
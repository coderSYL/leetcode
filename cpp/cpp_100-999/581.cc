// C++
// leetcode 581
// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
// 搞一个排序后的，然后对比
// 找到第一个不一样的和最后一个不一样的

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ordered(nums);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while(i < n && nums[i] == ordered[i])
            ++i;
        if(i == n)
            return  0;
        while(j > -1 && nums[j] == ordered[j])
            --j;
        return  j - i + 1;
    }
};
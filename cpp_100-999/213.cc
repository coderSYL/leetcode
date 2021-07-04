// C++
// leetcode 213
// https://leetcode-cn.com/problems/house-robber-ii/
// 套用 198题的解函数，改名为 rob_one

class Solution {
public:
    int rob_one(vector<int>& nums) {
        int n = nums.size();
        if( n == 0)
            return 0;
        int dp[n + 1];
        // 装入0与1
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size== 0)
            return 0;
        if(size ==1)
            return nums[0];
        int last = nums[size-1];
        nums.pop_back();
        int withoutLast = rob_one(nums);
        nums.push_back(last);
        nums.erase(nums.begin());
        int withoutBegin = rob_one(nums);
        return max(withoutBegin , withoutLast);
    }
};
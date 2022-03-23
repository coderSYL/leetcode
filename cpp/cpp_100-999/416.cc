// C++
// leetcode 416
// https://leetcode-cn.com/problems/partition-equal-subset-sum/
// 参考三叶，牛大惹


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 计算总和
        int sum = 0;
        for(auto x : nums)
            sum += x;

        // 和为奇数，寄
        if(sum % 2 == 1)
            return  false;

        int target = sum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;    // 表示初始选0个时可以选出和为0的组合

        for(int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];

            for(int j = target; j >= 0; j--) {
                // 使用i号物品
                bool yes =  (j - tmp >= 0 ? dp[j - tmp] : false);

                dp[j] = yes || dp[j];
            }
            if(dp[target])
                return  true;
        }
        return  false;
    }
};
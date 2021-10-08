// C++
// leetcode 494
// https://leetcode-cn.com/problems/target-sum/
// dp[i][j]，表示到了第i位时能使结果为 j-total 的方法有多少种


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0, n = nums.size();
        for(auto x:nums){
            total +=x;
        }

        // 够不着的情况
        if(total < target || target < -total)
            return 0;

        // 第一维代表已经处理过的数字的个数
        // 第二维代表和，且向右平移了total，例如初始 dp[0][total] = 1，代表0个数字和为0的情况有 1 种
        int dp[n+1][2 * total + 1];     
        memset(dp, 0, sizeof(dp));     // 全部初始化为0
        dp[0][total] =1;

        // 开始dp
        int left = total;   // left用于优化，表示剩下的数字所能达到的最大值，用它来减少
        for(int i = 1; i <= n; i++){
            int temp = nums[i - 1];   // 本次要处理的数字的值
            int begin_this_turn = max(-total, target - left);   // 本轮处理的开始的index
            int end_this_turn = min(total, target + left);      // 本轮处理的结束的index
            for(int j = begin_this_turn; j <= end_this_turn; j++){
                if(j - temp + total >= 0)
                    dp[i][j+total] += dp[i-1][j-temp+total];
                if(j + temp + total <= 2 * total)
                    dp[i][j+total] += dp[i-1][j+temp+total];
            }
            left -= temp;
        }
        return dp[n][target+total];
    }
};




// // 方法二：
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int total = 0, n = nums.size();
//         for(auto x : nums)
//             total += x;

//         // 够不着的情况
//         if(total < target || target < -total)
//             return 0;
//         if((total - target) % 2 == 1)
//             return  0;

//         // 绝对值和为 secondTarget 的子集的个数就是需要返回的值
//         int secondTarget = (total - target) / 2;
//         vector<int> dp(secondTarget + 1, 0);
//         vector<int> dp_temp(secondTarget + 1, 0);
//         dp[0] = 1;

//         for(int i = 0; i < n; i++) {
//             int temp = nums[i];
//             for(int j = 0; j + temp <= secondTarget; j++)
//                 dp_temp[j] = dp[j];
//             for(int j = 0; j + temp <= secondTarget; j++)
//                 dp[j + temp] += dp_temp[j];
//         }

//         return  dp[secondTarget];
//     }
// };
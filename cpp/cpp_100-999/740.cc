// C++
// leetcode 740
// https://leetcode-cn.com/problems/delete-and-earn/
// 经典dp

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int next = 0;
        int now= nums[0];
        int counter = 1;
        vector<int> howMany;
        for(int i = 1; i < n; ++i) {
            if(nums[i] == now)
                ++counter;
            else {
                nums[next] = now;
                ++next;
                howMany.push_back(counter);
                now = nums[i];
                counter = 1;
            }
        }
        // 结束后还有最后一对要处理
        nums[next++] = now;
        howMany.push_back(counter);
        vector<int> dp(next + 1);
        dp[0] = 0;
        dp[1] = howMany[0] * nums[0];
        bool taken = true;
        for(int i = 2; i <=next; ++i) {
            if(!taken || nums[i - 2] + 1 != nums[i - 1]) {
                taken = true;
                dp[i] = dp[i - 1] + howMany[i - 1] * nums[i - 1];
            } else {
                if(dp[i - 2] + howMany[i - 1] * nums[i - 1] > dp[i - 1]) {
                    // take
                    taken = true;
                    dp[i] = dp[i - 2] + howMany[i - 1] * nums[i - 1];
                } else {
                    taken = false;
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[next];
    }
};





// other's
// 比我的快

// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         map<int, int> hash;
//         for(const int &n: nums) hash[n]++;
//         int n = hash.size(), pre = -1, cnt = 1;
//         vector<int> dp(n+1, 0);
//         for(auto it = hash.begin(); it != hash.end(); it++){
//             int num = it->first;
//             if(num - 1 > pre){
//                 dp[cnt] = dp[cnt-1] + num * it->second;
//             } 
//             else{
//                 int temp = num * it->second + (cnt == 1 ? 0 : dp[cnt - 2]);
//                 dp[cnt] = max(dp[cnt-1], temp);
//             } 
//             pre = num;
//             cnt++;
//         }
//         return dp[n];
//     }
// };


/*
 * C++
 * leetcode740
 * url: https://leetcode-cn.com/problems/delete-and-earn/
 */

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> hash;
        for(const int &n: nums) hash[n]++;
        int n = hash.size(), pre = -1, cnt = 1;
        vector<int> dp(n+1, 0);
        for(auto it = hash.begin(); it != hash.end(); it++){
            int num = it->first;
            if(num - 1 > pre){
                dp[cnt] = dp[cnt-1] + num * it->second;
            } 
            else{
                int temp = num * it->second + (cnt == 1 ? 0 : dp[cnt - 2]);
                dp[cnt] = max(dp[cnt-1], temp);
            } 
            pre = num;
            cnt++;
        }
        return dp[n];
    }
};



// C++
// leetcode 300
// https://leetcode-cn.com/problems/longest-increasing-subsequence/
// dp[i]用来存储以nums[i]为结尾的最长子序列的大小，遍历一遍求得
// g[i] 用来存储长度为i的递增子序列的最小的结尾，
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size =nums.size(), ret = 1, temp = 0;
        int dp[size];
        vector<int> g(size+1, INT_MAX);
        for(int i = 0; i<size; i++){
            int l = 0, r = size;
            while(l < r) {
                int mid = (l + r + 1) / 2;
                if(g[mid] < nums[i])
                    l = mid;
                else
                    r = mid - 1;
            }
            int clen = r + 1;
            dp[i] = clen;
            g[clen] = min(g[clen], nums[i]);
            ret = max(ret, clen);
        }
        return ret;
    }
};
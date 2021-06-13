/*
 * C++
 * leetcode 354
 * url: https://leetcode-cn.com/problems/russian-doll-envelopes/
 * 先排个序，然后遍历一遍，算是比较典型的dp题目
 */

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return (a[0]>b[0] || (a[0]==b[0] && a[1]>=b[1]));
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmp);
        int size = envelopes.size();
        int dp[size], width[size], height[size], ret = 1;
        dp[0] = 1;
        width[0] = envelopes[0][0];
        height[0] = envelopes[0][1];
        for(int i =1; i<size; i++){
            dp[i] = 1;
            width[i] = envelopes[i][0];
            height[i] = envelopes[i][1];
            for(int j =0; j<i; j++){
                if(dp[j]>=dp[i] && height[j]>height[i] && width[j]>width[i])
                    dp[i] = dp[j] +1;
            }
            if(dp[i]>ret)
                ret = dp[i];
        }
        return ret;
    }
};
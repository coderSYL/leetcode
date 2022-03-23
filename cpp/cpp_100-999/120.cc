// C++
// leetcode 120
// https://leetcode-cn.com/problems/triangle/
// dp，反向


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> & dp = triangle[n - 1]; // 以最后一行作为进行dp的空间
        int leftToDeal = n - 1; // 剩余需要处理的次数
        while(leftToDeal > 0) {
            for(int i = 0; i < leftToDeal; i++) {
                dp[i] = min(dp[i], dp[i + 1]) + triangle[leftToDeal - 1][i];
            }
            leftToDeal--;
        }
        return  dp[0];
    }
};
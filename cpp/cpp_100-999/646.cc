// C++
// leetcode 646
// https://leetcode.cn/problems/maximum-length-of-pair-chain/
// 思路偷三叶的

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> f(n, 0);
        for (int i = 0; i < n; i++) {
            int x = pairs[i][0];
            for (int j = i - 1; j >= 0; j--) {
                if (pairs[j][1] < x) {
                    f[i] = f[j] + 1;
                    break;
                }
            }
            if (f[i] == 0)
                f[i]++;
        }
        return f[n - 1];
    }
};
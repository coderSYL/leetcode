// C++
// leetcode 周赛 2021-07-18
// https://leetcode-cn.com/contest/weekly-contest-250/problems/add-minimum-number-of-rungs/
// 第二题

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int n = rungs.size();
        int now = 0;
        int res = 0;
        for(int i = 0; i < n; ++i) {
            res += (rungs[i] - 1 - now) / dist;
            now = rungs[i];
        }
        return  res;
    }
};
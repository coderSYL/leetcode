// C++
// leetcode 1217
// https://leetcode.cn/problems/minimum-cost-to-move-chips-to-the-same-position/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt = 0, n = position.size();
        for(int i = 0; i < n; i++) {
            cnt += position[i] & 1;
        }
        return min(cnt, n - cnt);
    }
};
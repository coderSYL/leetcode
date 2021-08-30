// C++
// leetcode 双周赛 2021-08-21
// https://leetcode-cn.com/contest/biweekly-contest-59/problems/maximum-matrix-sum/
// 2

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int negativeCnt = 0;
        int mmm = INT_MAX;
        long long res = 0;
        for(auto line : matrix) {
            for(auto aNum : line) {
                if(aNum < 0) {
                    negativeCnt++;
                    aNum = -aNum;
                }
                if(aNum < mmm) {
                    mmm = aNum;
                }
                res += aNum;
            }
        }
        if(negativeCnt %2 == 0)
            return  res;
        else
            return res - 2 * mmm;
    }
};
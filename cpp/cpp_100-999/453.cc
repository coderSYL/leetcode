// C++
// leetcode 453
// https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
// 


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int min = nums[0];

        for(int i = 1; i < n; i++) {
            int nn = nums[i];
            if(nn < min) {
                res += (min - nn) * i;
                min = nn;
            } else {
                res += nn - min;
            }
        }

        return  res;
    }
};
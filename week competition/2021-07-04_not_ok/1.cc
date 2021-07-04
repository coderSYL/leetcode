// C++
// 周赛 2021-07-04
// 1

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; ++i) {
            res[i] = nums[ nums[i] ];
        }
        return res;
    }
};
// C++
// leetcode 1707
// https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/
// 

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(auto & pair : queries) {
            int x = pair[0];
            int m = pair[1];
            int temp = -1;
            for(auto & num : nums) {
                if(num > m) break;
                temp = max(temp, num ^ x);
            }
            res.push_back(temp);
        }
        return res;
    }
};
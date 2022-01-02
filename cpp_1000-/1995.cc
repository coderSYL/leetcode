// C++
// leetcode 1995
// https://leetcode-cn.com/problems/count-special-quadruplets/
// 偷的官方的思路

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> cnt;
        for (int c = n - 2; c >= 2; c--) {
            cnt[nums[c + 1]]++;
            for (int a = 0; a < c; ++a) {
                for (int b = a + 1; b < c; ++b) {
                	int sum = nums[a] + nums[b] + nums[c];
                    if (cnt.find(sum) != cnt.end()) {
                        res += cnt[sum];
                    }
                }
            }
        }
        return res;
    }
};
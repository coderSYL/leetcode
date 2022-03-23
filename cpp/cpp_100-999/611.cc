// C++
// leetcode 611
// https://leetcode-cn.com/problems/valid-triangle-number/
//

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for(int k = n -1; k > 1; --k) {
            int i = 0;
            int j = k - 1;
            while(i < j) {
                if(nums[i] + nums[j] > nums[k]) {
                    res += j - i;
                    --j;
                } else {
                    ++i;
                }
            }
        }
        return res;
    }
};
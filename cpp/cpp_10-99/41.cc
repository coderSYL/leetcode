// C++
// leetcode 41
// https://leetcode-cn.com/problems/first-missing-positive/
// 两轮遍历

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == i+1) continue;
            int u = nums[i];
            while((u != i+1) && (u <= nums.size()) && u > 0) {
                if(nums[i] == nums[u - 1])
                    break;
                swap(nums[i], nums[u - 1]);
                u = nums[i];
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1)
                return  i + 1;
        }
        return  nums.size() + 1;
    }
};
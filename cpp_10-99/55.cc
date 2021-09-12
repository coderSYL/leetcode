// C++
// leetcode 55
// https://leetcode-cn.com/problems/jump-game/
// 

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for(int i = 0; i < n; i++) {
            if(farthest < i)
                break;
            if(i + nums[i] > farthest)
                farthest = i + nums[i];
            if(farthest >= n - 1)
                return  true;
        }
        return  false;
    }
};
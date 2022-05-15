// C++
// leetcode 442
// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int val_i = nums[i];
            while(val_i != 0 && nums[val_i-1] != val_i) {
                nums[i] = nums[val_i-1];
                nums[val_i-1] = val_i;
                val_i = nums[i];
            }
            if(val_i != 0 && val_i != i+1) {
                res.push_back(val_i);
                nums[i] = 0;
                nums[val_i-1] = 0;
            }
        }
        return res;
    }
};
// C++
// leetcode 162
// https://leetcode-cn.com/problems/find-peak-element/
// 

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n =  nums.size();
        if(n == 1)  return  0;
        if(nums[0] > nums[1])   return  0;
        if(nums[n - 1] > nums[n - 2])   return  n - 1;

        
        int l = 0, r = n - 1;
        int mid;
        if(nums[1] > nums[n - 1])   mid = 1;
        else    mid = n - 2;


        while(l != r - 2) {
            if(l + 1 != mid) {
                int tmp = (l + mid) / 2;
                if(nums[tmp] > nums[mid]) {
                    r = mid;
                    mid = tmp;
                } else {
                    l = tmp;
                }
            } else {
                int tmp = (mid + r) / 2;
                if(nums[tmp] > nums[mid]) {
                    l = mid;
                    mid = tmp;
                } else {
                    r = tmp;
                }
            }
        }
        return  mid;
    }
};
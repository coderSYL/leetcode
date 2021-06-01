/*
 * C++
 * leetcode 1
 * url: https://leetcode-cn.com/problems/two-sum/
 * 复制一个nums的copy记为copy_nums
 * 对nums进行排序
 * 用双指针法找到符合的两个数，记为i,j
 * 回到copy_nums中找到i,j的index
 * 为避免i=j的情况，找i时从前往后找，找j时从后往前找
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy_nums (nums);
        int i =0, j = nums.size()-1, size = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ret;

        // try to find two numbers
        while(true){
            if(nums[i] +nums[j] > target){
                j--;
            }else if(nums[i] +nums[j] < target){
                i++;
            }else{
                i = nums[i];
                j = nums[j];
                break;
            }
        }
        // try to find index of 2 numbers
        for(int k =0; k<size; k++){
            if(copy_nums[k] == i){
                i = k;
                break;
            }
        }
        for(int k =size-1; k>=0; k--){
            if(copy_nums[k] == j){
                j = k;
                break;
            }
        }
        ret.push_back(i);
        ret.push_back(j);

        return ret;
    }
};
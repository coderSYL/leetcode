// c with stl(c++)
// 27
// https://leetcode-cn.com/problems/remove-element/
// 不用排序，直接双指针


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();

        for(int i =0; i<size; i++){
            if(nums[i] ==val){
                swap(nums[i],nums[size-1]);
                size--;
                i--;
            }
        }

        return size;
    }
};
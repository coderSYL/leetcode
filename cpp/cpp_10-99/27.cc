// C++
// leetcode 27
// https://leetcode-cn.com/problems/remove-element/
// 思路:
// 循环，每找到一个，就把它跟当前最后一个元素交换，然后把size--
// 再把i--，使得刚刚换过来的元素不会成为漏网之鱼
// 为了速度没有删除结尾多余的等于val的元素

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
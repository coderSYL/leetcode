// C++
// leetcode 11
// https://leetcode-cn.com/problems/container-with-most-water/
// 双指针
// 每次让底减少 1
// 选择减少左边还是右边：看哪边矮，减少矮的那边

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int size = height.size();
        int i = 0, val_i = height[i];
        int j = size - 1, val_j = height[j];
        int temp = 0;
        while(i<j){
            temp = (j - i) * (val_i < val_j?  val_i : val_j);
            ret = max(temp, ret);
            if(val_i < val_j) {
                i++;
                val_i = height[i];
            } else {
                j--;
                val_j = height[j];
            }
        }
        return ret;
    }
};
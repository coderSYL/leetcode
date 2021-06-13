/**
 * C++
 * leetcode 11
 * url: https://leetcode-cn.com/problems/container-with-most-water/
 * 双指针
 * 每次让底减少 1
 * 选择减少左边还是右边：看哪边矮，减少矮的那边
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int ret = 0, size = height.size(), i=0 , j=size-1, temp = 0, val_i = height[i], val_j = height[j];
    	while(i<j){
    		temp = (j-i) * (val_i<val_j? val_i:val_j);
    		if(temp >ret)
    			ret = temp;
    		if(val_i<val_j){
    			i++;
    			val_i = height[i];
    		}
    		else{
    			j--;
    			val_j = height[j];
    		}
    	}
    	return ret;
    }
};
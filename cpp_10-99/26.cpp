// c with stl(c++)
// 26
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
// 两个指针做标记，一个用来循环，另一个记录已经删好了的

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int size = nums.size();
    	if(size <2)
    		return size;
    	int i =0;
    	for(int j =1; j< nums.size(); j++){
    		if(nums[i] !=nums[j]){
    			i++;
    			nums[i]= nums[j];
    		}
    	}
    	return (i+1);
    }
};

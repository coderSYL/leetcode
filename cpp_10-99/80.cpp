// c with stl(c++)
// 80
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
// 两个指针做标记，一个用作循环的结束条件，另一个记录循环进行到的位置


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int counter =1;
    	int j = 1,i=1;
    	int size = nums.size();
    	if(size <3)
    		return size;
    	while(j<size){
    		if(nums[j] == nums[j-1]){
    			counter++;
    		}else{
    			counter =1;
    		}
    		if(counter<=2){
    			nums[i] = nums[j];
    			i++;
    		}
    		j++;
    	}
    	return i;
    }
};
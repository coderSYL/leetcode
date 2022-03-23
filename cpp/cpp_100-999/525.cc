/*
 * C++
 * leetcode 525
 * url: https://leetcode-cn.com/problems/contiguous-array/
 * 启发源自评论里的前缀和与hash
 * 将hash换成了一个数组，大小为 2*nums.size() +1
 * 前缀和需要将0换成-1来计算，这样的好处是，如果0与1数量相等，我们可以直接通过 prefix sum ==0 来判断
 * 循环处理一遍前缀和
 	* 如果前缀和为0则直接与全局ret判断
 	* 如果不为0，则需要看是否有同样前缀和的注册到数组中去了
 		* 数组预处理全为0，若为0则没注册过，把循环的i写进对应位置
 		* 由于数组index范围为 0~ 2*size， 前缀和可能出现的范围为 -size ~size， 数量相等，直接用前缀和+size代表它在数组中的位置，每次判断及注册需要先找到对应的index
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    	int size = nums.size(), ret = 0, local =0, temp_sum = 0, index= 0;
    	int sum[2*size+1];
    	memset(sum, 0, sizeof(sum));
    	for(int i =1; i<=size;i++){
    		// prefix sum 
    		if(nums[i-1] ==0)
    			temp_sum--;
    		else
    			temp_sum++;
    		// very good situation
    		if(temp_sum==0){
    			if(i>ret)
    				ret = i;
    			continue;
    		}
    		// find index
    		index = temp_sum+size;
    		// judge, register or find a local max length
    		if(sum[index] ==0)
    			sum[index] = i;
    		else{
    			local = i - sum[index];
    			if(local>ret)
    				ret = local;
    		}
    	}
    	return ret;
    }
};
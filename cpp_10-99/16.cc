/**
 * C++
 * leetcode 16
 * url: https://leetcode-cn.com/problems/3sum-closest/
 * 先排序
 * 用i遍历作第一个数字
 * 然后j,k双指针
 * 使用ret记录需要返回的值，用decalage记录 ret 与target的绝对值，并且使用decalage作为更改ret的依据
 */

class Solution {
public:
    int abso(int a, int b){
        if(a>b) return a-b;
        return b-a;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort( nums.begin(), nums.end());
        if(nums[0] + nums[1] +nums[2] >target)
            return nums[0] + nums[1] +nums[2];
        if(nums[size-1] +nums[size-2] +nums[size-3] <target)
            return nums[size-1] +nums[size-2] +nums[size-3];
        int i, j, k, i_val, j_val, k_val, temp;
        int ret, decalage = INT_MAX;
        for( int i =0; i<size-2; i++)
        {
            i_val = nums[i];
            j = i+1;
            j_val = nums[j];
            k = size-1;
            k_val = nums[k];
            while(j<k)
            {   
                temp = i_val+j_val+k_val;
                if(abso(temp, target) < decalage)
                {
                    ret = temp;
                    decalage = abso(temp, target);
                }
                if(temp > target)
                {   // 刷k
                    while(nums[k] ==k_val && j<k)
                        k--;
                    k_val = nums[k];
                }
                else if(temp < target)
                {   // 刷j
                    while(nums[j] ==j_val && j<k)
                        j++;
                    j_val = nums[j];
                }else{
                    return target;
                }
            }
        }   // end i loop
        return ret;
    }
};
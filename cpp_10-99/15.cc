/**
 * C++
 * leetcode 15
 * url: https://leetcode-cn.com/problems/3sum/
 * 先排序
 * 一个循环确定第一个数，注意，第一个数重了就跳过，不然会造成重复答案
 * 然后双指针确定第二个数与第三个数，注意，刷数的时候要确保刷后与刷前大小不一样
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ret;
        if(size < 3)
            return ret;
        sort(nums.begin(), nums.end());
        int j, k, j_val, k_val, need, last_need = INT_MIN;
        for(int i =0; i< size-2; i++){
            need = -nums[i];
            if(last_need == need)
                continue;
            else
                last_need = need;
            j = i+1;
            j_val = nums[j];
            k = size-1;
            k_val = nums[k];
            while(j<k){
                if(j_val + k_val > need)
                {   
                    while(nums[k] == k_val && j<k)
                        k--;
                    k_val = nums[k];
                }
                else if(j_val + k_val < need)
                {
                    while(nums[j] == j_val && j<k)
                        j++;
                    j_val = nums[j];
                }
                else
                {   
                    ret.push_back(vector<int>{-need, j_val, k_val});
                    while(nums[j] == j_val && j<k)
                        j++;
                    j_val = nums[j];
                    while(nums[k] == k_val && j<k)
                        k--;
                    k_val = nums[k];
                }
            }
        }
        return ret;
    }
};
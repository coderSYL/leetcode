// C++
// leetcode 18
// url: https://leetcode-cn.com/problems/4sum/
// 思路:
// 原数组小于4个元素返回空
// 排序
// 最大四个和小于target返回空
// 最小四个和大于target返回空
// 然后i，j两层循环，确定前两个数
// k，l双指针确定后两个数
// 符合的答案就装入ret

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        int size =nums.size(), temp;
        if(size < 4)
            return ret;
        sort( nums.begin(), nums.end());
        if(nums[0] +nums[1] +nums[2] +nums[3] >target)
            return ret;
        if(nums[size-1] + nums[size-2] + nums[size-3] +nums[size-4] <target)
            return ret;
        int i, j, k, l, i_val, j_val, k_val, l_val, before_i_val =INT_MIN, before_j_val = INT_MIN;
        int last_3 =INT_MIN, last_4 = INT_MIN;
        for(int i =0; i< size-3; i++)
        {// i loop
            if(nums[i]==before_i_val)
            {   
                continue;
            }
            else
            {
                i_val = nums[i];
            }
            before_j_val = INT_MIN;
            for(int j = i+1; j<size-2; j++)
            {// j loop
                if( nums[j]==before_j_val)
                {
                    continue;
                }
                else
                {
                    j_val = nums[j];
                }
                k = j+1;
                k_val = nums[k];
                l =size-1;
                l_val = nums[l];
                while(k<l)
                {   // two pointers loop
                    temp = i_val +j_val +k_val +l_val;
                    if(temp <target)
                    {
                        // 刷k
                        while(nums[k]==k_val && k<l)
                            k++;
                        k_val = nums[k];
                    }
                    else if(temp> target)
                    {
                        // 刷l
                        while(nums[l]==l_val && k<l)
                            l--;
                        l_val =nums[l];
                    }
                    else
                    {
                        ret.push_back(vector<int>{i_val, j_val, k_val, l_val});
                        // 刷k与l
                        while(nums[k]==k_val && k<l)
                            k++;
                        k_val = nums[k];
                        while(nums[l]==l_val && k<l)
                            l--;
                        l_val =nums[l];
                    }
                }   // end two pointer loop
                before_j_val = j_val;
            }   // end j loop
            before_i_val = i_val;
        }   // end i loop
        return ret;
    }
};
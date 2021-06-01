/*
 * C++
 * leetcode 477
 * url: https://leetcode-cn.com/problems/total-hamming-distance/
 * 从每位分析，有32位，分析第i位
 * 如果是0，那么它与其他1会产生距离1，有 num_1 个 1
 * 有 nums.size() -num_1 个0
 * 所以对于每一位，产生的距离总量就是(nums.size() -num_1) * num_1
 */

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sz = nums.size(), i =32, num_1 = 0, ret = 0;
        while(i>0){
            num_1 = 0;
            for(int &n : nums){
                if(n%2 ==1)
                    num_1++;
                n = n/2;
            }
            ret += num_1 * (sz - num_1);
            i--;
        }
        return ret;
    }
};
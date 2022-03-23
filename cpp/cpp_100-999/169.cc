// C++
// leetcode 169
// https://leetcode-cn.com/problems/majority-element/
// 遍历一遍，记一个数和次数，相同则++不同则--
// 最后检查一下是否是那个数

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = -1;
        int counter = 0;
        for(auto x : nums) {
            if(x == res)
                ++counter;
            else if (counter == 0) {
                res = x;
                counter = 1;
            } else 
                --counter;
        }

        // check一下
        int n = nums.size();
        counter = 0;
        for(auto x : nums)
            if(x == res)
                counter++;

        if(counter > n / 2)
            return res;
        return -1;
    }
};
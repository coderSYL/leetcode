// C++
// leetcode 645
// https://leetcode-cn.com/problems/set-mismatch/
// 使用 map 标记 nums 中各个数字出现的次数
// 因为数字范围是[1,n]，所以用数组代替了map
// 找没出现过的数字时，用求和来避免再一次的循环遍历

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exist(n+1, false);
        int total = n * (n + 1) / 2;
        int sum = 0;
        int setSum = 0;
        for(auto& x : nums) {
            sum += x;
            if(!exist[x]) {
                exist[x] = true;
                setSum += x;
            }
        }
        return vector<int>{sum - setSum, total -setSum}; // { 重复的, 少了的 }
    }
};
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



// // 方法二
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n = nums.size();
//         int cnt[n + 1];
//         memset(cnt, 0, sizeof(cnt));
//         vector<int> res(2);
//         int p = 0;
//         for (auto x : nums)
//             cnt[x]++;
//         for (int i = 1; i <= n; i++) {
//             if (cnt[i] == 0) {
//                 res[1] = i;
//             } else if (cnt[i] == 2)
//                 res[0] = i;
//         }
//         return res;
//     }
// };
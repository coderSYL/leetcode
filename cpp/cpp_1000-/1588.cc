// C++
// leetcode 1588
// https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
// 前缀和，化简

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int total = 0;
        for(auto & x : arr) {
            total += x;
            x = total;
        }

        int res = 0;
        int n = arr.size();
        int len = 1;
        while(len <= n) {
            for(int i = 0; i < len -1; i++)
                res -= arr[i];
            for(int i = n - 1; i >= n - len; i--)
                res += arr[i];
            len += 2;
        }

        return  res;
    }
};
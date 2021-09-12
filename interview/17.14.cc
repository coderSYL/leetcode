// C++
// leetcode 面试17.14
// https://leetcode-cn.com/problems/smallest-k-lcci/
// 

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> res(k);
        for(int i = 0; i < k; i++) {
            res[i] = arr[i];
        }
        return res;
    }
};
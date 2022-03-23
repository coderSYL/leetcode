// C++
// leetcode 46
// https://leetcode-cn.com/problems/permutations/
// 利用一个order数组来算排列，每次算出下一个排列，然后填装数据，插入res中，直到回归最初的排列

class Solution {
public:
    // 用来指示是否排列完成，跨函数使用，故写在类里
    bool exist = true;

    // 翻转函数
    // 让vector a中的l到r的数据反转
    void rev(vector<int>& a, int l, int r) {
        while(l < r) {
            swap(a[l], a[r]);
            l++;
            r--;
        }
    }

    // 获得a的下一个排列，n为a的大小
    void nextPermutation(vector<int>& a, int n) {
        int i = n - 2;
        while(i >= 0) {
            if(a[i] > a[i + 1])
                i--;
            else
                break;
        }
        if(i == -1) {
            exist = false;
            return;
        }
        int k = n - 1;;
        while(a[k] < a[i]) {
            k--;
        }
        swap(a[i], a[k]);
        rev(a, i+1, n - 1);
        exist = true;
    }


    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> order(n);
        for(int i = 0; i < n; i++) {
            order[i] = i;
        }
        vector<vector<int>> res;
        res.push_back(nums);
        vector<int> temp(nums);
        int cnt = 0;
        while(true) {
            nextPermutation(order, n);
            if(exist) {
                for(int i = 0; i < n; i++) {
                    temp[i] = nums[order[i]];
                }
                res.push_back(temp);
            } else {
                break;
            }
        }
        return  res;
    }
};
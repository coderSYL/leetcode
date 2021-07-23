// C++
// leetcode 1893
// https://leetcode-cn.com/problems/check-if-all-the-integers-in-a-range-are-covered/
// 类似桶排

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool check[52] = {false};
        for(auto a : ranges) {
            for(int i = a[0]; i <= a[1]; ++i)
                check[i] = true;
        }
        for(int i = left; i <= right; ++i) {
            if(!check[i])
                return false;
        }
        return true;
    }
};
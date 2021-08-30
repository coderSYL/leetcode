// C++
// leetcode 1646
// https://leetcode-cn.com/problems/get-maximum-in-generated-array/
// 简单一次遍历

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0)
            return  0;
        vector<int> num(n + 1, 0);
        num[1] = 1;
        int i = 1;
        int res = 1;
        while(i < n) {
            i++;
            if(i % 2 == 0) {
                // 偶数
                num[i] = num[i / 2];
            } else {
                // 奇数
                num[i] = num[i / 2] + num[i / 2 + 1];
            }
            res = max(res, num[i]);
        }
        return  res;
    }
};
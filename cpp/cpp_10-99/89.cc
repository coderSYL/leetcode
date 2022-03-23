// C++
// leetcode 89
// https://leetcode-cn.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1<<n);
        int idx = 0;
        res[idx++] = 0;
        int head = 1;
        while(idx < res.size()) {
            for (int j = idx - 1; j >= 0; j--)
                res[idx++] = res[j] + head;
            head *= 2;
        }
        return res;
    }
};
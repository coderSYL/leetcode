// C++
// leetcode 670
// https://leetcode.cn/problems/maximum-swap/

class Solution {
public:
    int maximumSwap(int num) {
        // tmp 数组记录
        vector<int> tmp;
        // 数组 m 记录低位的最大值
        vector<int> m;
        int cur = 0;
        while(num) {
            int u = num%10;
            num /= 10;
            tmp.push_back(u);
            m.push_back(cur);
            cur = max(cur, u);
        }

        // 寻找一次能使数最大的交换
        int n = tmp.size();
        for (int i = n-1; i > 0; i--) {
            if (m[i] > tmp[i]) {
                for (int j = 0; j < i; j++) {
                    if (tmp[j] == m[i]) {
                        tmp[j] = tmp[i];
                        tmp[i] = m[i];
                        break;
                    }
                }
                break;
            }
        }

        // 把 tmp 数组重组成答案
        int res = 0;
        for (int i = n-1; i >= 0; i--) {
            res = res * 10 + tmp[i];
        }
        return res;
    }
};
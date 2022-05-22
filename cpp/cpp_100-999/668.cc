// C++
// leetcode 668
// https://leetcode.cn/problems/kth-smallest-number-in-multiplication-table/

class Solution {
public:
    int m_, n_;
    int findKthNumber(int m, int n, int k) {
        m_ = max(m, n);
        n_ = min(m, n);
        int l = 1, r = m * n;
        while(l < r) {
            int mid = (l+r) >> 1, cnt = getCnt(mid);
            if(cnt >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }

    int getCnt(int val) {
        int a = 0, b = 0;
        for(int i = 1; i <= n_; ++i) {
            if(i * m_< val) {
                a += m_;
            } else {
                if(val % m_== 0 && ++b >= 0) {
                    a += val / i - 1;
                } else {
                    a += val / i;
                }
            }
        }
        return a + b;
    }
};
// C++
// leetcode 1802
// https://leetcode.cn/problems/maximum-value-at-a-given-index-in-a-bounded-array/

class Solution {
public:
    long n, idx, maxSum, l, r;
    int maxValue(int n_, int index_, int maxSum_) {
        n = n_;
        idx = index_;
        maxSum = maxSum_;
        l = idx;
        r = n - idx - 1;
        
        long ll = 1, rr = maxSum_;
        while (ll <= rr) {
            long mid = (ll + rr) >> 1;
            if (check(mid))
                ll = mid + 1;
            else
                rr = mid - 1;
        }
        return (int)ll - 1;
    }

    bool check(long val) {
        long l_val = val - l, r_val = val - r;
        long sum = val;

        if (l_val <= 0)
            sum += val * (val - 1) / 2 + (1 - l_val);
        else 
            sum += (l_val + val -1) * l / 2;

        if (r_val <= 0)
            sum += val * (val - 1) / 2 + (1 - r_val);
        else
            sum += (r_val + val - 1) * r / 2;

        return sum <= maxSum;
    }
};
// C++
// leetcode 1814
// https://leetcode.cn/problems/count-nice-pairs-in-an-array/

class Solution {
public:
    int MOD = (int)1e9 + 7;

    // 得到 rev(a)
    long getRev(long a) {
        long res = 0;
        while (a) {
            res = res * 10 + a % 10;
            a /= 10;
        }
        return res;
    }

    int countNicePairs(vector<int>& nums) {
        map<long, int> cnt;
        for (int x : nums) {
            long u = x;
            cnt[u - getRev(u)]++;
        }
        long res = 0;
        for (auto [k,v] : cnt) {
            res += (long)v * (v - 1) / 2;
            res %= MOD;
        }
        return (int)res;
    }
};
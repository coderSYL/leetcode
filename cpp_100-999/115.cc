// C++
// leetcode 115
// https://leetcode-cn.com/problems/distinct-subsequences/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<unsigned> f(n + 1, 0);
        f[n] = 1;
        for(int i = m - 1; i >= 0; i--) {
            // i 到 s末尾的距离，m - i
            // 应该大于等于 j 到 t末尾的距离， n - j
            // m - i >= n - j  =>  j >= n - m + i
           for(int j = max(n - m + i, 0); j < n; j++) {
            if(s[i] == t[j])
                f[j] += f[j + 1];
           }
        }
        return  f[0];
    }
};
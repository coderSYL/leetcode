// C++
// leetcode 1044
// https://leetcode-cn.com/problems/intest-duplicate-substring/

using ull = unsigned long long;
class Solution {
   public:
    string longestDupSubstring(string s) {
        int P = 1313131, n = s.length();
        vector<ull> h(n + 10);
        vector<ull> p(n + 10);
        p[0] = 1;
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] * P;
            h[i + 1] = h[i] * P + s[i];
        }
        string ans;
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            string t = check(s, mid, h, p);
            if (t.length() != 0) {
                l = mid;
            } else {
                r = mid - 1;
            }
            ans = t.length() > ans.length() ? t : ans;
        }
        return ans;
    }

   private:
    string check(string &s, int len, vector<ull> &h,
                 vector<ull> &p) {
        int n = s.length();
        unordered_set<ull> set;
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            ull cur = h[j] - h[i - 1] * p[j - i + 1];
            if (set.count(cur) != 0) {
                return s.substr(i - 1, len);
            }
            set.emplace(cur);
        }
        return "";
    }
};
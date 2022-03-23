// C++
// leetcode 76
// https://leetcode-cn.com/problems/minimum-window-substring/
// 滑动窗口，一遍循环，每次右滑一位，并且看看左侧能不能收缩

class Solution {
public:
    void plus(int* a, char c) {
        if(c < 'a')
            a[c - 'A']++;
        else
            a[c - 'a' + 26]++;
    }

    void minus(int* a, char c) {
        if(c < 'a')
            a[c - 'A']--;
        else
            a[c - 'a' + 26]--;
    }

    int get(int * a, char c) {
        if(c < 'a')
            return a[c - 'A'];
        else
            return a[c - 'a' + 26];
        return -1; // error
    }

    string minWindow(string s, string t) {
        int cnt[52] = {0};
        int cur[52] = {0};
        for(auto c : t)
            plus(cnt, c);

        string  res;
        int good = 0;

        for(int i = 0, j = 0; j < s.size(); j++) {
            char c = s[j];
            plus(cur, c);
            if(get(cur, c) <= get(cnt, c))
                good++;
            while(i <= j && get(cur, s[i]) > get(cnt, s[i])) {
                minus(cur, s[i]);
                i++;
            }
            if(good == t.size() && (res.empty() || res.size() > j - i + 1))
                res = s.substr(i, j - i + 1);
        }
        return  res;
    }
};
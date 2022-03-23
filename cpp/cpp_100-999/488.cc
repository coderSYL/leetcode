// C++
// leetcode 488
// https://leetcode-cn.com/problems/zuma-game/
// 爆搜dfs + 剪枝


class Solution {
public:
    int INF = 0x3f3f3f3f;
    string b_;
    unordered_map<string, int>  map;

    int findMinStep(string a, string b) {
        b_ = b;
        int res = dfs(a, 1 << b.size());
        return  (res == INF ? -1 : res);
    }

    int dfs(string a, int cur) {
        // 已经完事了
        if(a.size() == 0)   return  0;
        // 之前算过
        if(map.find(a) != map.end())    return  map[a];
        int res = INF;
        int n = a.size();
        // 遍历所有的球
        for(int i = 0; i < b_.size(); i++) {
            // 球被用过
            if(((cur >> i) & 1) == 1)   continue;
            // 如果球没有用过，使用这个球
            int next = (1 << i) | cur;
            char ball  = b_[i];
            for(int j = 0; j <= n; j++) {
                // 剪枝，对AA来说，射1跟射2都是一样的
                if(j < n - 1 && a[j] == a[j + 1])  continue;
                // 不同，射了消不了
                if(j > 0 && j < n - 1 && a[j] != b_[i]) continue;
                // 用 next_string 来记录射完后的局面
                string next_string = a.substr(0, j) + ball + a.substr(j, n);
                clean(next_string, j);
                res = min(res, dfs(next_string, next) + 1);
            }
        }
        map[a] = res;
        return res;
    }

    void clean(string &s, int pos) {
        if(pos < 0 || pos >= s.size()) return;
        char c = s[pos];
        int l = pos, r = pos;
        while(l >= 0 && s[l] == c)
            l--;
        while(r < s.size() && s[r] == c)
            r++;
        if(r - l - 1 >= 3) {
            s.erase(l + 1, r - l - 1);
            clean(s, l);
        }
    }
};
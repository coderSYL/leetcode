// C++
// leetcode 421
// https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
// 字典树


class Solution {
public:
    int N = 650000;
    int trie[650000][2];
    int idx = 0;

    void add(int x) {
        int p = 0;
        for(int i = 31; i >= 0; i--) {
            int u = x>>i & 1;
            if(trie[p][u] == 0)
                trie[p][u] = ++idx;
            p = trie[p][u];
        }
    }

    int getVal(int x) {
        int ret = 0;
        int p = 0;
        for(int i = 31; i >= 0; i--) {
            int a = (x >> i) & 1, b = 1 - a;
            if(trie[p][b] != 0) {
                ret += (1 << i);
                p = trie[p][b];
            } else {
                p = trie[p][a];
            }
        }
        return  ret;
    }

    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        memset(trie, 0, sizeof(trie));
        for(auto x : nums) {
            add(x);
            res = max(res, getVal(x));
        }
        return  res;
    }
};
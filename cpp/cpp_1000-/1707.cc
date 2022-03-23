// C++
// leetcode 1707
// https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/
// 

class Solution {
public:
    int N = 1800000;    // N是测出来的
    int trie[1800000][2] = {{0}};
    int idx = 0;

    struct Three {
        int x;
        int limit;
        int index;
        Three(int x, int limit, int index) : x(x), limit(limit), index(index) {}

        bool operator<(const Three& a) const {
            return  limit < a.limit;
        }
    };

    void add(int x) {
        int p = 0;
        for(int i = 31; i >= 0; i--) {
            int u = (x >> i) & 1;
            if(trie[p][u] == 0)
                trie[p][u] = ++idx;
            p = trie[p][u];

        }
    }

    int getVal(int x) {
        // 得到字典树中与x异或后最大的值
        int val = 0;
        int p = 0;
        for(int i = 31; i >= 0; i--) {
            int u = (x >> i) & 1;
            if(trie[p][1 - u] != 0) {
                val += (1 << i);
                p = trie[p][1 - u];
            } else {
                p = trie[p][u];
            }
        }
        return val;
    }

    static bool cmp(vector<int> a, vector<int> b) {
        return  a[1] < b[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res(queries.size(), -1);
        // 对nums进行排序
        sort(nums.begin(), nums.end());

        vector<Three>   qs;
        for(int i = 0; i < queries.size(); i++) {
            qs.push_back(Three(queries[i][0], queries[i][1], i));
        }
        sort(qs.begin(), qs.end());

        int done = 0;
        for(auto x : qs) {
            int a = x.x, b = x.limit;
            while(done < nums.size() && nums[done] <= b)
                add(nums[done++]);
            if(idx != 0) {
                res[x.index] = getVal(a);
            }
        }
        return  res;
    }
};
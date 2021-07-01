// C++
// leetcode LCP 7
// https://leetcode-cn.com/problems/chuan-di-xin-xi/
// DFS？

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        unordered_set<int> canPassTo[n];
        for(auto pair : relation)
            canPassTo[pair[0]].insert(pair[1]);
        return DFS(0, n - 1, canPassTo, k);
    }

    int DFS(int from, int to, unordered_set<int> *p, int times) {
        if(times == 1) 
            return  p[from].count(to);
        int res = 0;
        for(auto x : p[from])
            res += DFS(x, to, p, times - 1);
        return res;
    }
};

// k * n * max(one person can pass)
// class Solution {
// public:
//     int numWays(int n, vector<vector<int>>& relation, int k) {
//         unordered_set<int> canPassTo[n];
//         for(auto pair : relation)
//             canPassTo[pair[0]].insert(pair[1]);
//         vector<int> res(n, 0);
//         res[0] = 1;
//         while(k > 0) {
//             --k;
//             vector<int> next(n, 0);
//             for(int i = 0; i < n; ++i) {
//                 if(res[i] == 0)
//                     continue;
//                 int temp = res[i];
//                 for(auto x : canPassTo[i]) {
//                     next[x] += temp;
//                 }
//             }
//             next.swap(res);
//         }
//         return res[n -1];
//     }
// };
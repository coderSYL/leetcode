// C++
// leetcode 1337
// https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/
//

class Solution {
public:
    static bool cmp(pair<int , int> a, pair<int , int> b) {
        if(a.second != b.second)
            return  a.second < b.second;
        return  a.first < b.first;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector< pair<int , int> >   helper(n); // < line index , power >
        for(int i = 0; i < n; ++i) {
            int l = 0, r = m - 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                if(mat[i][mid] == 0)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            helper[i] = make_pair(i , l);
        }
        sort(helper.begin(), helper.end(), cmp);
        vector<int> res(k);
        for(int i = 0; i < k; ++i) {
            res[i] = helper[i].first;
        }
        return  res;
    }
};
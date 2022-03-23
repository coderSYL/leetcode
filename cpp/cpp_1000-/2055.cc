// C++
// leetcode 2055
// https://leetcode-cn.com/problems/plates-between-candles/

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n+1);
        sum[0] = 0;
        vector<int> bar;
        for(int i = 0; i < n; i++) {
            if(s[i] == '|') {
                bar.push_back(i);
                sum[i+1] = sum[i];
            }
            else
                sum[i+1] = sum[i] + 1;
        }
        int res_size = queries.size();
        vector<int> res(res_size, 0);
        if(bar.size() == 0)
            return res;
        for(int i=0; i < res_size; i++) {
            int a = queries[i][0], b = queries[i][1];
            int c = -1, d = -1;
            int l = 0, r = bar.size()-1;
            while(l < r) {
                int mid = (l + r) >> 1;
                if(bar[mid] >= a) r = mid;
                else l = mid + 1;
            }
            if(bar[r] >= a)
                c = bar[r];
            else continue;
            l = 0;
            r = bar.size()-1;
            while(l < r) {
                int mid = (l + r + 1) >> 1;
                if(bar[mid] <= b) l = mid;
                else r = mid - 1;
            }
            if(bar[r] <= b) d = bar[r];
            else continue;
            if(c <= d)
                res[i] = sum[d+1] - sum[c];
        }
        return res;
    }
};
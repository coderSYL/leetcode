// C++
// leetcode 39
// https://leetcode-cn.com/problems/combination-sum/
// dfs

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        // sort(candidates.begin(), candidates.end());
        return  recursion(candidates, target, 0, n);
    }

    vector<vector<int>> recursion(vector<int>& c, int t, int startPoint, int n) {
        vector<vector<int>> res;
        if(t < 0)
            return  res;
        vector<int> temp;
        if(t == 0) {
            res.push_back(temp);
            return  res;
        }
        if(startPoint == n) {
            return  res;
        }
        int now = c[startPoint];
        int p = 0;
        while(t - p * now >= 0) {
            for(auto& x : recursion(c, t - p * now, startPoint + 1, n)) {
                int pp = p;
                while(pp > 0) {
                    x.push_back(now);
                    pp--;
                }
                res.push_back(x);
            }
            p++;
        }
        return  res;
    }
};
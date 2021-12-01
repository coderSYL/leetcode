// C++
// leetcode 39
// https://leetcode-cn.com/problems/combination-sum/
// dfs + 剪点枝

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(vector<int>& cs, int done, int left) {
        if(left == 0) {
            res.push_back(cur);
            return;
        }
        if(done == cs.size())
            return;

        int u = cs[done];
        int max = left / u;
        if(max == 0)
            return;
        cur.insert(cur.end(), max, u);
        left -= max * u;
        dfs(cs, done + 1, left);
        while(max--) {
            cur.pop_back();
            left += u;
            dfs(cs, done + 1, left);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return  res;
    }
};
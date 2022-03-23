// C++
// leetcode 40
// https://leetcode-cn.com/problems/combination-sum-ii/
// dfs回溯

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<int>   cnt;
    int size = 0;

    void dfs(vector<int>& cs, int done, int left) {
    	// 合格
        if(left == 0) {
            res.push_back(cur);
            return;
        }
        // 试完了还没合格
        if(done == size) return;
        // 本次 dfs 使用的数字以及它的数量
        int u = cs[done];
        int n = min(cnt[done], left / u);
        // 一个都塞不进了（因cs是升序排列，故之后的肯定也塞不进
        if(n == 0)  return;
        // 塞 n 个进去
        cur.insert(cur.end(), n, u);
        left -= n * u;
        // dfs，然后每排出一个再dfs一次
        dfs(cs, done + 1, left);
        while(n--) {
            left += u;
            cur.pop_back();
            dfs(cs, done + 1, left);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // 预处理，计数
        int now = candidates[0], cc = 1;
        for(int i = 1; i < candidates.size(); i++) {
            if(candidates[i] == now) {
                cc++;
            } else {
                candidates[size++] = now;
                cnt.push_back(cc);
                now = candidates[i];
                cc = 1;
            }
        }
        candidates[size++] = now;
        cnt.push_back(cc);
        dfs(candidates, 0, target);
        return  res;
    }
};
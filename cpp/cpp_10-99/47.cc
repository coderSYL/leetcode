// C++
// leetcode 47
// https://leetcode-cn.com/problems/permutations-ii/
// 效率不高

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    int idx = 0;
    int full;

    void dfs(vector<int>& nums, int lastProcessed, int info) {
        if(idx == nums.size()) {
            res.push_back(cur);
            return;
        }
        // possible 为 1 的位表示本次dfs可以选
        int possible = full & (~info);
        for(int i = 0; i < nums.size(); i++) {
            if((possible & (1 << i))== 0)   continue;
            int u = nums[i];
            int n = 1;
            int j = i;
            while(++j < nums.size() && nums[j] == u)
                n++;
            // 不等于上一个，则本轮可使用
            if(u != lastProcessed) {
                int nextInfo = info;
                for(int m = 0; m < n; m++) {
                    cur[idx++] = u;
                    nextInfo |= (1 << (i + m));
                    dfs(nums, u, nextInfo);
                }
                idx -= n;
            }
            i += n - 1;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        full = (1 << nums.size()) - 1;
        cur.resize(nums.size());
        sort(nums.begin(), nums.end());
        dfs(nums, INT_MAX, 0);
        return  res;
    }
};
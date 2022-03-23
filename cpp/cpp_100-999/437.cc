// C++
// leetcode 437
// https://leetcode-cn.com/problems/path-sum-iii/
// 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    int target;
    vector<int> list;

    void dfs(TreeNode* p, int level) {
        if(p == nullptr)
            return;
        // 先把这层录进去
        if(list.size() <= level) {
            list.push_back(list[level - 1] + p->val);
        } else {
            list[level] = list[level - 1] + p->val;
        }
        // 然后寻找target
        int l = 0, r = level - 1;
        int targetForThisDfs = list[level] - target;
        for(int i = 0; i < level; i++) {
            if(targetForThisDfs == list[i])
                res++;
        }
        dfs(p->left, level + 1);
        dfs(p->right, level + 1);
    }

    int pathSum(TreeNode* root, int targetSum) {
        res = 0;
        list.push_back(0);
        target = targetSum;
        dfs(root, 1);
        return  res;
    }
};
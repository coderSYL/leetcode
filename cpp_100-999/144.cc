// C++
// leetcode 144
// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

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
    void dfs(vector<int> &v, TreeNode* root) {
        v.push_back(root->val);
        if(root->left) dfs(v, root->left);
        if(root->right) dfs(v, root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root) dfs(res, root);
        return res;
    }
};
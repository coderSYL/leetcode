// C++
// leetcode 94
// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// 递归


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
    vector<int> res;

    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
        mid(root);
        return  res;
    }

    void mid(TreeNode* p) {
        if(p == nullptr)
            return;
        mid(p->left);
        res.push_back(p->val);
        mid(p->right);
    }
};
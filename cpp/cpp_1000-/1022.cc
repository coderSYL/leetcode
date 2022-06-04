// C++
// leetcode 1022
// https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/

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
    int sumRootToLeaf(TreeNode* root) {
    	int res = 0;
    	inside(root, 0, res);
        return res;
    }

    void inside(TreeNode* root, int cur, int &res) {
    	cur = (cur<<1) + root->val;
        if(root->left == nullptr && root->right == nullptr) {
            res += cur;
            return;
        }
    	if(root->left) inside(root->left, cur, res);
    	if(root->right) inside(root->right, cur, res);
    }
};
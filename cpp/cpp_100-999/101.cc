// C++
// leetcode 101
// https://leetcode-cn.com/problems/symmetric-tree/
// 感觉略慢，能跑就行

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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return  true;
        vector<TreeNode*>    left;
        vector<TreeNode*>    right;
        if(root->left == nullptr && root->right == nullptr)
            return   true;
        else if(root->left == nullptr || root->right == nullptr)
            return   false;
        else {
            left.push_back(root->left);
            right.push_back(root->right);
        }
        
        int next = 0;
        while(next < left.size()) {
            auto l = left[next];
            auto r = right[next];
            next++;
            if(l->val != r->val)
                return  false;
            if(l->left == nullptr && r->right == nullptr) {
                // void
            } else if(l->left == nullptr || r->right == nullptr) {
                return  false;
            } else {
                left.push_back(l->left);
                right.push_back(r->right);
            }

            if(r->left == nullptr && l->right == nullptr) {
                // void
            } else if(r->left == nullptr || l->right == nullptr) {
                return  false;
            } else {
                right.push_back(r->left);
                left.push_back(l->right);
            }
        }
        return  true;
    }
};
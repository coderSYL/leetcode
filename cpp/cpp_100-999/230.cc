// C++
// leetcode 230
// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
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
private:
    int kk;
    set<int>    s;

    void mid(TreeNode* root) {
        if(root == nullptr)
            return;
        int vv = root->val;

        if(s.size() < kk) {
            s.insert(vv);
        } else {
            int big = *(s.rbegin());
            if(vv < big) {
                s.erase(big);
                s.insert(vv);
            }
        }

        mid(root->left);
        mid(root->right);
    }


public:
    int kthSmallest(TreeNode* root, int k) {
        kk = k;
        mid(root);
        return *(s.rbegin());
    }
};
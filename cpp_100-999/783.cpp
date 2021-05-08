// c with stl(c++)
// 783
// https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
// 递归中序遍历，然后判断

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
    void visit(vector<int>& vec, TreeNode* root,int& record){
        int size = vec.size();
        vec.push_back(root->val);
        if(size != 0){
            if(vec[size] - vec[size-1]< record)
                record = vec[size] - vec[size-1];
        }
        return;
    }
    void MidOrder(vector<int>& vec, TreeNode* root,int& record){
        if(root){
            if(root->left){
                MidOrder(vec, root->left, record);
            }
            visit(vec, root, record);
            if(root->right){
                MidOrder(vec, root->right, record);
            }
            return;
        }
    }

    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        int res = INT_MAX;
        MidOrder(vec, root, res);
        return res;
    }
};
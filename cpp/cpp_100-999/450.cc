// C++
// leetcode 450
// https://leetcode.cn/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        // 根节点就是
    	if(root->val == key) {
    		if(root->left) {
    			if(root->right) {
    				// 左右子树都存在
    				TreeNode *l = root->left, *r = root->right;
    				while(l->right != nullptr)
    					l = l->right;
    				l -> right = r;
    				return root->left;
    			} else {
    				return root->left;
    			}
    		}
    		return root->right;
    	} else if(root->val > key) {
    		TreeNode *tmp = deleteNode(root->left, key);
    		root->left = tmp;
    		return root;
    	} else {
    		TreeNode *tmp = deleteNode(root->right, key);
    		root->right = tmp;
    		return root;
    	}
    	return nullptr;
    }
};
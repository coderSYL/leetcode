// C++
// leetcode 102
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
        	return	res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
        	int size = q.size();
        	vector<int> cur;
        	while(size--) {
        		auto p = q.front();
        		q.pop();
        		cur.push_back(p -> val);
        		if(p -> left)
        			q.push(p->left);
        		if(p->right)
        			q.push(p->right);
        	}
        	res.push_back(cur);
        }
        return	res;
    }
};
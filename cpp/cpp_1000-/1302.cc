// C++
// leetcode 1302
// https://leetcode.cn/problems/deepest-leaves-sum/

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
    int deepestLeavesSum(TreeNode* root) {
    	int sum = 0;
    	queue<TreeNode*> q;
        q.push(root);
    	TreeNode* p;
    	while (!q.empty()) {
    		int sz = q.size();
    		sum = 0;
    		while (sz--) {
    			p = q.front();
    			sum += p->val;
    			q.pop();
    			if (p -> left)
    				q.push(p->left);
    			if (p -> right)
    				q.push(p->right);
    		}
    	}
    	return sum;
    }
};
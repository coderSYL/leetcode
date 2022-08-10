// C++
// leetcode 623
// https://leetcode.cn/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    	if (depth == 1) {
    		return new TreeNode(val, root, nullptr);
    	}

    	dfs(root, 1, depth, val);

    	return root;

    }

    void dfs(TreeNode *p, int cur, int target_depth, int val) {
    	if (cur >= target_depth)
    		return;

    	if (cur + 1 == target_depth) {
    		TreeNode *newL = new TreeNode(val, p -> left, nullptr);
    		TreeNode *newR = new TreeNode(val, nullptr, p -> right);
    		p -> left = newL;
    		p -> right = newR;
    		return ;
    	}

    	if (p -> left)
    		dfs(p -> left, cur + 1, target_depth, val);

    	if (p -> right)
    		dfs(p -> right, cur + 1, target_depth, val);
    }
};
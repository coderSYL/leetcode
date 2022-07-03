// C++
// leetcode 515
// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
    	vector<int> res;
    	if(root == nullptr)
    		return res;
    	queue<TreeNode*> q;
    	q.push(root);
    	int max_cur, size;
    	while(!q.empty()) {
    		size = q.size();
    		max_cur = INT_MIN;
    		while(size--) {
    			auto p = q.front();
    			q.pop();
    			max_cur = max(max_cur, p->val);
    			if(p->left) {
    				q.push(p->left);
    			}
    			if(p->right) {
    				q.push(p->right);
    			}
    		}
    		res.push_back(max_cur);
    	}
    	return res;
    }
};
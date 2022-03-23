// C++
// leetcode 1609
// https://leetcode-cn.com/problems/even-odd-tree/
// 两个队列来回滚动
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
    bool isEvenOddTree(TreeNode* root) {
    	queue<TreeNode*> q1;
    	queue<TreeNode*> q2;
    	if(root->val % 2 == 0) return false;
    	q1.push(root);
    	bool q1IsEvenLevel = true;
    	while(!q1.empty()) {
    		int left = (q1IsEvenLevel ? 0 : 1);
    		while(!q1.empty()) {
    			auto p = q1.front();
    			q1.pop();
    			auto pp = p->left;
    			if(pp != nullptr) {
    				if(pp->val % 2 != left) return false;
    				if(!q2.empty()) {
    					int diff = pp->val - q2.back()->val;
    					if(q1IsEvenLevel) {
    						if(diff >= 0) return false;
    					} else {
    						if(diff <= 0) return false;
    					}
    				}
    				q2.push(pp);
    			}
    			pp = p->right;
    			if(pp != nullptr) {
    				if(pp->val % 2 != left) return false;
    				if(!q2.empty()) {
    					int diff = pp->val - q2.back()->val;
    					if(q1IsEvenLevel) {
    						if(diff >= 0) return false;
    					} else {
    						if(diff <= 0) return false;
    					}
    				}
    				q2.push(pp);
    			}
    		}
    		q1IsEvenLevel = !q1IsEvenLevel;
    		q1.swap(q2);
    	}
    	return true;
    }
};
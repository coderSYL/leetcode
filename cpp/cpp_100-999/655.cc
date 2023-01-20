// C++
// leetcode 655
// https://leetcode.cn/problems/print-binary-tree/

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
    vector<vector<string>> printTree(TreeNode* root) {
    	int depth = 0, m = 1;
    	queue<TreeNode*> q;
    	q.push(root);
    	TreeNode* tmp;

    	// find depth
    	while (!q.empty()) {
    		int size = q.size();
    		m <<= 1;
    		depth++;
    		while(size--) {
    			tmp = q.front();
    			q.pop();
    			if (tmp -> left)
    				q.push(tmp -> left);
    			if (tmp -> right)
    				q.push(tmp -> right);
    		}
    	}

    	vector<vector<string>> res(depth, vector<string>(m - 1, ""));
    	queue<pair<TreeNode*, int>> qq;


    	qq.push(make_pair(root, (m - 2) / 2));
    	int level = 0;
    	int idx = -1, d = m>>2;
    	while (!qq.empty()) {
    		int size = qq.size();
    		while (size--) {
    			tmp = qq.front().first;
    			idx = qq.front().second;
    			res[level][idx] = to_string(tmp -> val);
    			qq.pop();
    			if (tmp -> left)
    				qq.push(make_pair(tmp -> left, idx - d));
    			if (tmp -> right)
    				qq.push(make_pair(tmp -> right, idx + d));
    		}
    		level++;
    		d >>= 1;
    	}

    	return res;
    }
};
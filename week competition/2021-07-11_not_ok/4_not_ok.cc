// C++
// leetcode 
// https://leetcode-cn.com/contest/weekly-contest-249/problems/merge-bsts-to-create-single-bst/
// 周赛4

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
	map<int, pair<TreeNode*, bool> > bot;
	// 左false，右true

	void update(TreeNode* root) {
		TreeNode* l = root->left;
		TreeNode* r = root->right;
		if(l != nullptr) {
			if(l->left == nullptr && l->right == nullptr) {
				bot[l->val] = pair<TreeNode*, bool>(root, false);
			} else {
				update(l);
			}
		}
		if(r != nullptr) {
			if(r->left == nullptr && r->right == nullptr) {
				bot[r->val] = pair<TreeNode*, bool>(root, true);
			} else {
				update(r);
			}
		}
	}

	bool isBST(TreeNode* root, int big, int small) {
		TreeNode* l = root->left;
		TreeNode* r = root->right;
		if(!(root->val < big && root->val > small))
			return false;
		bool l_ok = true;
		bool r_ok = true;
		if(l != nullptr)
			l_ok = isBST(l, min(big, root->val), small);
		if(r != nullptr)
			r_ok = isBST(r, big, max(small, root->val));
		return l_ok && r_ok;

	}

    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n = trees.size();
        bot.clear();
        for(auto root : trees) {
        	update(root);
        }
        TreeNode* res = nullptr;

        for(auto root : trees) {
        	auto it = bot.find(root->val);
        	if(it == bot.end()) {
        		// 不存在
        		if(res == nullptr)
        			res = root;
        		else
        			return nullptr;
        	} else {
        		// 存在，需要拼接一下
        		if(it->second.second) {
        			// 右子树
        			it->second.first->right = root;
        		} else {
        			// 左子树
        			it->second.first->left = root;
        		}
        	}
        }
        if(res != nullptr)
        	if(!isBST(res, INT_MAX, INT_MIN))
        		return nullptr;
        return res;
    }
};
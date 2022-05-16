// C++
// leetcode interview 04.06
// https://leetcode.cn/problems/successor-lcci/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode* pp;
	bool need_this_one = false;
	bool done = false;
	void mid(TreeNode* ptr) {
		// 空指针或者结束了
		if(done || !ptr)
			return;
		// 左
		mid(ptr->left);
		// 本节点
		if(done)
			return;	// 防止左的时候结束了而错刷
		if(need_this_one) {	// 符合结束条件
			pp = ptr;
			done = true;
			return;
		}
		if(ptr == pp) { // 到了下一个点
			need_this_one = true;
		}
		mid(ptr->right);
	}
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    	need_this_one = false; done = false;
    	pp = p;
    	mid(root);
    	if(!done)
    		return nullptr;
    	return pp;
    }
};

// // 非递归方法，借助stack，且改变了原树
// class Solution {
// public:
//     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
//     	stack<TreeNode*> s;
//     	TreeNode *pre = nullptr, *cur = root;
//     	s.push(root);
//         int turn = 1;
//     	while(!s.empty()) {
//     		TreeNode *cur = s.top();
//     		if(cur->left != nullptr && pre != cur->left) {
//     			// 左子树存在且没搞过，全搞一遍
//     			while(cur->left) {
//     				TreeNode *l = cur->left;
//     				s.push(l);
//     				cur->left = nullptr; // 涉及到二叉树的修改
//     				cur = l;
//     			}
//     			continue;
//     		}
//     		// 可以办了
//     		if(pre == p)
//     			return cur;
//     		pre = cur;
//     		s.pop();
//     		if(cur->right)
//     			s.push(cur->right);
//     	}

//     	return nullptr;
//     }
// };
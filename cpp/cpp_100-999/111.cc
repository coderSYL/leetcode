// C++
// leetcode 111
// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
    	if(root == nullptr)
    		return	0;
    	if(root -> left == nullptr && root -> right == nullptr)
    		return	1;
    	if(root -> left == nullptr)
    		return	minDepth(root -> right) + 1;
    	if(root -> right == nullptr)
    		return	minDepth(root -> left) + 1;
    	return	min(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
};


// // 方法二，双队列互刷，稍微快一点
// class Solution {
// public:
//     int res = 1;
//     queue<TreeNode*>    q;
//     queue<TreeNode*>    q_next;

//     void set(TreeNode* root) {
//         q.push(root);
//         while(!(q.empty() && q_next.empty())) {
//             while(!q.empty()) {
//                 auto x = q.front();
//                 if(x -> left == nullptr && x -> right == nullptr)
//                     return;
//                 if(x -> left != nullptr)
//                     q_next.push(x -> left);
//                 if(x -> right != nullptr)
//                     q_next.push(x -> right);
//                 q.pop();
//             }
//             q.swap(q_next);
//             res++;
//         }
//     }
//     int minDepth(TreeNode* root) {
//     	if(root == nullptr)
//     		return	0;
//         set(root);
//         return  res;
//     }
// };
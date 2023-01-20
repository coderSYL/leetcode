// C++
// leetcode 662
// https://leetcode.cn/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        // 队列 <结点指针, 索引>
        queue<pair<TreeNode*, long>> q;
        q.push(make_pair(root, 1));

        int res = 0;

        while (!q.empty()) {
            // 每个循环处理一层节点
            int size = q.size();
            // 以最左边节点的索引作为最小值mn
            long mn = q.front().second;
            TreeNode *p = nullptr;
            long idx = -1;

            while(size--) {
                // 每个循环处理一个节点
                p = q.front().first;
                idx = q.front().second;
                q.pop();
                if (p->left)    // 每次索引都减去mn以防溢出
                    q.push(make_pair(p->left, (idx - mn) * 2));
                if (p->right)
                    q.push(make_pair(p->right, (idx - mn) * 2 + 1));
                if (size == 0)
                    res = max(res, (int)(idx - mn + 1));
            }
        }
        return res;
    }
};
// C++
// leetcode 671
// https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/
// 简简单单一波先序遍历

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
    bool m1Set = false, m2Set = false;
    int m1 = INT_MAX, m2 = INT_MAX;
    void first(TreeNode* root) {
        // 需要确保root肯定非空指针
        // 先搞val部分
        if(root == nullptr)
            return;
        int temp = root->val;
        if(!m1Set) {
            m1Set = true;
            m1 = temp;
        }else if(!m2Set) {
            if(temp != m1) {
                m2Set = true;
                if(temp < m1) {
                    m2 = m1;
                    m1 = temp;
                } else {
                    m2 = temp;
                }
            }
        }else if(temp < m2 && temp != m1) {
            if(temp < m1) {
                m2 = m1;
                m1 = temp;
            } else {
                m2 = temp;
            }
        }
        first(root -> left);
        first(root -> right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        first(root);
        if(!m2Set)
            return -1;
        return m2;
    }
};
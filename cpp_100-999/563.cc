// C++
// leetcode 563
// https://leetcode-cn.com/problems/binary-tree-tilt/

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
    int findSum(TreeNode *r, int &ans) {
        if(r == nullptr)
            return  0;
        int leftSum = findSum(r ->left, ans);
        int rightSum = findSum(r ->right, ans);
        int diff = leftSum - rightSum;
        ans += (diff > 0 ? diff : -diff);
        return  leftSum + rightSum + r -> val;
    }

    int findTilt(TreeNode* root) {
        if(root == nullptr)
            return  0;
        int res = 0;
        findSum(root, res);
        return  res;
    }
};
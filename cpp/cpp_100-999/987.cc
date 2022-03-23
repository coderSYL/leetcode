// C++
// leetcode 987
// https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/
// 自己想的方法略繁琐，然后根据评论里的方法改进了

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
    map<int , multiset<int> >    m;

    void helper(TreeNode* r, int level, int index) {
        if(r == nullptr)
            return;
        m[index].insert(level * 100000 + r->val);
        helper(r->left, level + 1, index -1);
        helper(r->right, level + 1, index +1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 1, 0);
        vector<vector<int>> res;
        for(auto p : m) {
            vector<int> temp;
            for(auto x : p.second) {
                temp.push_back(x % 10000);
            }
            res.push_back(temp);
        }
        return  res;
    }
};
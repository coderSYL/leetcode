/*
 * C++
 * leetcode 501
 * url: https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/
 * 中序遍历二叉树
 * 用4个值，记录most, most_time, now, now_time
 * visit(int)函数中进行now, now_time的更新
 * jieSuan()中进行most, most_time的更新
 * 最后需要结算一次
 */

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
    int now = INT_MIN;
    int now_time = 0;
    vector<int> most;
    int most_time = 0;

    void jieSuan(){
        if(now_time > most_time){
            most.clear();
            most.push_back(now);
            most_time = now_time;
        }else if(now_time == most_time){
            most.push_back(now);
        }
    }

    void visit(int a){
        if(now_time ==0){
            now = a;
            now_time =1;
        }else if(a == now){
            now_time++;
        }else{
            jieSuan();
            now = a;
            now_time =1;
        }
    }

    void mid(TreeNode* root){
        if(!root)
            return;
        mid(root->left);
        visit(root->val);
        mid(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        mid(root);
        jieSuan();
        return most;
    }
};
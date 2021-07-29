// C++
// leetcode 863
// https://leetcode-cn.com/problems/all-nodes-distance-k-in-binary-tree/solution/
// 先用map建立数组的数，然后利用建好的map来从target开始搜索

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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, int>   treeNum;
        map<int, int>   nodeVal;
        queue<TreeNode*>    q;
        treeNum[root] = 1;
        q.push(root);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            int num = treeNum[temp];
            nodeVal[num] = temp->val;
            if(temp -> left) {
                treeNum[temp->left] = 2 * num;
                q.push(temp->left);
            }
            if(temp -> right) {
                treeNum[temp->right] = 2 * num + 1;
                q.push(temp->right);
            }
        }
        int t = treeNum[target];
        map<int, int> dist;
        dist[t] = 0;
        queue<int>  qn;
        qn.push(t);
        vector<int> res;
        while(!qn.empty()) {
            int this_loop = qn.front();
            qn.pop();
            int d =dist[this_loop];
            if(d == k)
                res.push_back(nodeVal[this_loop]);
            if(d > k)
                break;
            int maybe = this_loop/2;
            if(nodeVal.find(maybe) != nodeVal.end() && dist.find(maybe) == dist.end()) {
                dist[maybe] = d + 1;
                qn.push(maybe);
            }
            maybe = 2 * this_loop;
            if(nodeVal.find(maybe) != nodeVal.end() && dist.find(maybe) == dist.end()) {
                dist[maybe] = d + 1;
                qn.push(maybe);
            }
            ++maybe;
            if(nodeVal.find(maybe) != nodeVal.end() && dist.find(maybe) == dist.end()) {
                dist[maybe] = d + 1;
                qn.push(maybe);
            }
        }
        return  res;
    }
};
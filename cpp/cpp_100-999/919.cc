// C++
// leetcode 919
// https://leetcode.cn/problems/complete-binary-tree-inserter/

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
class CBTInserter {
public:
    int treeSize = 0;
    TreeNode *root;

    CBTInserter(TreeNode* r) {
        root = r;

        int res = 0;
        TreeNode *tmp = nullptr;

        queue<TreeNode*> q;
        q.push(r);
        while (!q.empty()) {
            int size = q.size();
            res += size;

            // check if it's the last level
            if (size * 2 -1 != res)
                break;

            // put next level into the queue
            while(size--) {
                tmp = q.front();
                q.pop();
                if (tmp -> left)
                    q.push(tmp -> left);
                else
                    break;
                if (tmp -> right)
                    q.push(tmp -> right);
                else
                    break;
            }

            while (size-- > 0)
                q.pop();
        }

        treeSize = res;
    }
    
    int insert(int val) {
        int cur = ++treeSize;
        int depth = 0;
        while(cur != 0) {
            cur >>= 1;
            depth += 1;
        }
        cur = treeSize;

        TreeNode *p = root;
        for (int i = depth - 2; i > 0; i--) {
            int u = 1 & (cur >> i);
            if (u == 0) {
                p = p -> left;
            } else {
                p = p -> right;
            }
        }
        // till now, p is the pointer of the father of new TreeNode

        // insert new TreeNode
        if ((cur & 1) == 0) {
            p -> left = new TreeNode(val);
        } else {
            p -> right = new TreeNode(val);
        }

        return p -> val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
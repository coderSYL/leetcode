// C++
// leetcode 449
// https://leetcode.cn/problems/serialize-and-deserialize-bst/
// 序列化方法，每个数字范围都在[1,10000],可以用16bit表示，占两个字符
// 按先序遍历来序列化

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int partOne = (1<<8) - 1;
    vector<char> vchar;
    
    void preOrder(TreeNode* root) {
        if(!root) return;
        int a = root->val;
        vchar.push_back(a>>8);
        vchar.push_back(a&partOne);
        preOrder(root->left);
        preOrder(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";
        preOrder(root);
        string res(vchar.begin(), vchar.end());
        vchar.clear();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        int n = data.size();
        vector<int> tmp;
        for(int i = 0; i < n; i += 2) {
            int first = data[i];
            int second = (data[i+1] + 256 )% 256;
            int cur = (first<<8) + second;
            tmp.push_back(cur);
        }
        return inside(tmp, 0, tmp.size()-1);

    }

    TreeNode* inside(vector<int> &v, int l, int r) {
        int cur = v[l];
        TreeNode* ret = new TreeNode(cur);
        int mid = l + 1;
        while(mid <= r && v[mid] < cur)
            mid++;
        if(l < mid-1)
            ret->left = inside(v, l+1, mid-1);
        if(mid <= r)
            ret->right = inside(v, mid, r);
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
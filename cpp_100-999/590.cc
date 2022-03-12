// C++
// leetcode 590
// https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
	void inner(vector<int> &res, Node* root) {
		for(auto child : root->children) {
			inner(res, child);
		}
		res.push_back(root->val);
	}
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root != nullptr)
        	inner(res,root);
        return res;
    }
};
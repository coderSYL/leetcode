// C++
// leetcode 429
// https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
        	return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
        	vector<int> tmp;
        	int size = q.size();
        	while(size--) {
        		Node *p = q.front();
        		q.pop();
        		tmp.push_back(p -> val);
        		for(auto &child : p->children)
        			q.push(child);
        	}
        	res.push_back(tmp);
        }
        return res;
    }
};
// C++
// leetcode 559
// https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/

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
	int res = 0;

	void dfs(Node* root, int depth) {
		if(root == nullptr)	return;
		res = max(res, ++depth);
		for(auto p : root -> children) {
			dfs(p, depth);
		}
	}

    int maxDepth(Node* root) {
        dfs(root, 0);
        return	res;
    }
};
// C++
// leetcode 427
// https://leetcode-cn.com/problems/construct-quad-tree/

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
	Node* tool(vector<vector<int>>& grid, int top, int down, int left, int right) {
		if (top == down) {
				return (Node*)new Node(grid[top][left] == 1, true);
		}

		int horizontal_mid = (left + right) / 2;
		int vertical_mid = (top + down) / 2;
		Node* topLeft = tool(grid, top, vertical_mid, left, horizontal_mid);
		Node* topRight = tool(grid, top, vertical_mid, horizontal_mid+1, right);
		Node* bottomLeft = tool(grid, vertical_mid+1, down, left, horizontal_mid);
		Node* bottomRight = tool(grid, vertical_mid+1, down, horizontal_mid+1, right);
		if(topLeft==nullptr && topRight==nullptr && bottomLeft==nullptr && bottomRight==nullptr)
			return nullptr;

		int base = 0, cur = 0;
		bool all_is_leaf = true;
		if(topLeft) {
			base++;
			all_is_leaf &= topLeft->isLeaf;
			cur += topLeft->val;
		}
		if(topRight) {
			base++;
			all_is_leaf &= topRight->isLeaf;
			cur += topRight->val;
		}
		if(bottomLeft) {
			base++;
			all_is_leaf &= bottomLeft->isLeaf;
			cur += bottomLeft->val;
		}
		if(bottomRight) {
			base++;
			all_is_leaf &= bottomRight->isLeaf;
			cur += bottomRight->val;
		}
		// cout<<base<<"base - cur "<<cur<<endl;
		if((base == cur || cur == 0)&&all_is_leaf) {
			delete topLeft;
			delete topRight;
			delete bottomLeft;
			delete bottomRight;
			return (Node*)new Node(cur == base, true);
		}
		return (Node*)new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
	}

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return tool(grid, 0, n-1, 0, n-1);
    }
};
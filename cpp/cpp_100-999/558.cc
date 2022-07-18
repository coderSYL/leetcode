// C++
// leetcode 558
// https://leetcode.cn/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/

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
	void becomeNotLeaf(Node *p) {
		if(!(p -> isLeaf)) {
			return;
		}
		p -> isLeaf = false;
		p -> topLeft = new Node(p->val, true);
		p -> topRight = new Node(p->val, true);
		p -> bottomLeft = new Node(p->val, true);
		p -> bottomRight = new Node(p->val, true);
	}

	int deal(Node *r) {
		if (r -> isLeaf) {
			return (r -> val ? 1 : -1);
		}

		int sum = deal(r -> topLeft) + deal(r -> topRight) + deal(r -> bottomLeft) + deal(r -> bottomRight);
		if(sum == 4 || sum == -4) {
			r -> val = (sum == 4);
			delete r-> topLeft;
			delete r-> topRight;
			delete r-> bottomLeft;
			delete r-> bottomRight;
			r -> topLeft = nullptr;
			r -> topRight = nullptr;
			r -> bottomLeft = nullptr;
			r -> bottomRight = nullptr;
			r->isLeaf = true;
		}

		return sum / 4;
	}

    Node* intersect(Node* r1, Node* r2) {
        // 遍历 r1，且对 r2 进行同操作
        vector<Node*> q1{r1}, q2{r2}, qq1, qq2;

        while (!q1.empty()) {
        	int n1 = q1.size(), n2 = q2.size();
        	bool allIsLeaf = true;
        	for (int i = 0; allIsLeaf && i < n1; i++) {
        		allIsLeaf = q1[i] -> isLeaf;
        	}

        	for (int i = 0; allIsLeaf && i < n2; i++) {
        		allIsLeaf = q2[i] -> isLeaf;
        	}

        	if (allIsLeaf) {
        		// 全是叶子，可以结算了
        		for (int i = 0; i < n1; i++) {
        			q1[i]->val = q1[i]->val || q2[i]->val;
        		}
        		break;
        	}

        	// 非全叶子
        	Node *p1, *p2;
        	qq1.resize(4 * n1);
        	qq2.resize(4 * n2);
        	for(int i = 0, j = 0; i < n1; i++) {
        		p1 = q1[i];
        		p2 = q2[i];
        		becomeNotLeaf(p1);
        		becomeNotLeaf(p2);
        		qq1[j] = p1 -> topLeft;
        		qq2[j++] = p2 -> topLeft;
        		qq1[j] = p1 -> topRight;
        		qq2[j++] = p2 -> topRight;
        		qq1[j] = p1 -> bottomLeft;
        		qq2[j++] = p2 -> bottomLeft;
        		qq1[j] = p1 -> bottomRight;
        		qq2[j++] = p2 -> bottomRight;
        	}
        	q1.swap(qq1);
        	q2.swap(qq2);
        }
        deal(r1);
        return r1;
    }
};
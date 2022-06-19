// C++
// leetcode offerII 029
// https://leetcode.cn/problems/4ueAj6/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
	// put b after a in a linklist
	void ins(Node* a, Node* b) {
		Node* tmp = a->next;
		a->next = b;
		b->next = tmp;
	}

    Node* insert(Node* he, int x) {
    	Node *tmp = new Node(x), *res = he;
    	// n = 0
        if(he == nullptr) {
        	tmp->next = tmp;
        	return tmp;
        }

        int min_val = he->val, max_val = he->val;
        do {
        	min_val = min(min_val, he->val);
        	max_val = max(max_val, he->val);
        	he = he->next;
        } while (he != res);

        int v = 0;
        if(min_val == max_val) {
        	// one value for all nodes
        	ins(res, tmp);
        	return res;
        } else if (x <= min_val || x >= max_val) {
        	// max_val -> x -> min_val
        	while(!(he->val == max_val && he->next->val == min_val)) {
        		he = he->next;
        	}
        	ins(he, tmp);
        	return res;
        } else {
        	while(!(he->val <= x && he->next->val > x)) {
        		he = he->next;
        	}
        	ins(he, tmp);
        	return res;
        }
        return res;
    }
};
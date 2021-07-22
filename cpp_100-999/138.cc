// C++
// leetcode 138
// https://leetcode-cn.com/problems/copy-list-with-random-pointer/
// 

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
        	return	nullptr;
        Node* p = head;
        map<Node*, Node*> m;
        while(p != nullptr) {
        	m[p] = new Node(p->val);
        	p = p->next;
        }
        m[nullptr] = nullptr;
        p = head;
        Node* q = nullptr;
        while(p != nullptr) {
        	q = m[p];
        	q->next = m[p->next];
        	q->random = m[p->random];
        	p = p->next;
        }
        return m[head];
    }
};
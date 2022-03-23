// C++
// leetcode 430
// https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
// 输出顺序跟先序遍历一致，不用专门弄出序列再拼接，可以直接一边遍历一边处理


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    stack<Node*>    s;
    Node* flatten(Node* head) {
        if(head == nullptr)
            return  nullptr;
        auto p = head;
        while(p->child != nullptr || p->next != nullptr || !s.empty()) {
            if(p->child != nullptr) {
                // 子非空，入子，把指针修正为通往子路，把next加入s
                p->child->prev = p;
                if(p->next != nullptr)
                    s.push(p->next);
                p->next = p->child;
                p->child = nullptr;
                p = p->next;
            } else if(p->next != nullptr) {
                // 子空，next非空，p入next
                p = p->next;
            } else {
                // 子跟next都空
                p->next = s.top();
                s.top()->prev = p;
                p = p->next;
                s.pop();
            }
        }
        return  head;
    }
};
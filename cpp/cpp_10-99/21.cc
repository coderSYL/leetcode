// C++
// leetcode 21
// url: https://leetcode-cn.com/problems/merge-two-sorted-lists/
// 思路:
// 用两个指针处理两个链表，一一比对，只到其中一个链表为空
// 用一个头指针和一个尾指针维护需要返回的ret链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        ListNode* p1 =l1;
        ListNode* p2 = l2;
        ListNode* ret_head, *ret_end;
        if(l1->val < l2->val)
        {// l1 is head
            ret_head = l1;
            p1 = p1->next;
            ret_end = ret_head;
        }
        else
        {// l2 is head
            ret_head = l2;
            p2 = p2->next;
            ret_end = ret_head;
        }
        while(p1!= nullptr && p2!= nullptr)
        {
            if(p1->val < p2->val)
            {
                ret_end->next = p1;
                ret_end = p1;
                p1 = p1->next;
            }
            else
            {
                ret_end->next = p2;
                ret_end = p2;
                p2 = p2->next;
            }
        }
        if(p1 !=nullptr)
        {
            ret_end->next = p1;
        }
        if(p2 != nullptr)
        {
            ret_end->next = p2;
        }
        return ret_head;
    }
};
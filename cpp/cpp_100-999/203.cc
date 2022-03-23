/*
 * C++
 * leetcode 203
 * url: https://leetcode-cn.com/problems/remove-linked-list-elements/
 * 比较简单的解题顺序
 * 先判断head的值是否为val，找到第一个不为val的结点作为head
 * 然后在逐一判断后面的结点，判断流程需要记 工作结点p 与 它前面的结点pre，方便必要时删除结点p 并把剩下的链表连起来
 */

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p =head, *pre = nullptr;
        while(head != nullptr && head->val ==val){
            head = head->next;
            // free(p);     // 题目貌似不让free
            p = head;
        }   // 找到一个值非val的结点
        if(!head)
            return head;
        pre = head;
        p = p->next;
        while(p != nullptr){
            if(p->val == val)
            {   // 需要删除
                pre->next = p->next;
                // free(p);
                p = pre->next;
            }
            else
            {   // 不需删除
                pre = p;
                p = p->next;
            }
        }
        return head;
    }
};
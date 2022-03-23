// C++
// leetcode offer 52
// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
// 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLengthOfNode(ListNode *head) {
        int length = 0;
        while(head != nullptr) {
            ++length;
            head = head->next;
        }
        return  length;
    }


    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLengthOfNode(headA);
        int lenB = getLengthOfNode(headB);
        if(lenA > lenB) {
            int diff = lenA - lenB;
            while(diff > 0) {
                headA = headA -> next;
                --diff;
            }
            lenA = lenB;
        } else {
            int diff = lenB - lenA;
            while(diff > 0) {
                headB = headB -> next;
                --diff;
            }
            lenB = lenA;
        }
        // 至此，两个链表指针已根据(到结尾的距离)对齐
        while(headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        return  headB;
    }
};
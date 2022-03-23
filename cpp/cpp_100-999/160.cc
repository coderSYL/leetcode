/*
 * C++
 * leetcode 160
 * url: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * 求两个链表长度，把指针对齐到距结尾一样的距离，然后开始一一比对
 */

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
    int getSize(ListNode *p){
        int ret = 0;
        while(p!=nullptr){
            p=p->next;
            ret++;
        }
        return ret;
    }

    ListNode * getAfter(ListNode *p,int i){     // pick a nice int i
        while(i>0){
            p = p->next;
            i--;
        }
        return p;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int a = getSize(headA), b = getSize(headB);
        if(a>b){
            headA = getAfter(headA,a-b);
            a = b;
        }
        if(b>a){
            headB = getAfter(headB, b-a);
            b= a;
        }
        while(headA!=nullptr && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
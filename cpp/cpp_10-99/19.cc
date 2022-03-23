// C++
// leetcode 19
// url: https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
// 思路:
// 使用一个指针数组存储链表所有指针（因为结点数小于等于30所以用数组，如果结点数很大且不定，则用vector
// 存完后找到需要操作删除的结点，按要求删掉再返回头结点指针

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp[31];
        int next = 0;
        while(head!=nullptr){
            temp[next] = head;
            next++;
            head = head->next;
        }
        temp[next] = nullptr;
        if(n==next)
            return temp[1];
        temp[ next-n-1]->next = temp[ next-n+1];
        return temp[0];
    }
};
// C++
// leetcode offer 22
// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
// 简单

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* ha[k];
        int next = 0;
        while(head != nullptr) {
            ha[next] = head;
            next = (next + 1) % k;
            head = head->next;
        }
        return  ha[next];
    }
};
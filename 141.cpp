// c with stl(c++)
// 141
// https://leetcode-cn.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }

        ListNode *fast = head->next, *slow =head;
        while(fast !=NULL){
            if( fast ==slow)
                return true;
            fast = fast->next;
            slow = slow->next;
            if(fast != NULL)
                fast = fast->next;
        }
        return false;
    }
};
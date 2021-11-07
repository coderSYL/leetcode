// C++
// leetcode 82
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
// 


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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(head == nullptr || head -> next == nullptr)
    		return	head;

    	int original = head -> val;
    	ListNode* p = head -> next;
    	if(p -> val == original) {
    		// 需要减少
    		while(p != nullptr && p -> val == original)
    			p = p->next;
    		if(p == nullptr)
				return	p;
			else
				return	deleteDuplicates(p);
    	} else {
    		// 不需要减少
    		head -> next = deleteDuplicates(p);
    		return	head;
    	}
    	return	nullptr; // never
    }
};
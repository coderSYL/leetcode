// C++
// leetcode 83
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

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
    	if(head == nullptr)	return	nullptr;

    	ListNode* end = head, *p = head -> next;
    	while(true) {
	    	while(p != nullptr && p -> val == end -> val)
	    		p = p -> next;
	    	if(p == nullptr)	break;
	    	// 此时p为一个与end不同值的结点
	    	end -> next = p;
	    	end = p;
	    }
	    end -> next = nullptr;
	    return	head;
    }
};
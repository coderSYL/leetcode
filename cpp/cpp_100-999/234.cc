// C++
// leetcode 234
// https://leetcode.cn/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* he) {
    	ListNode *fast = he, *slow = he;
    	bool end_in_middle = false;
    	// find mid, slow is mid
    	while(fast->next != nullptr) {
    		slow = slow -> next;
    		fast = fast->next;
    		if(fast->next != nullptr) {
    			fast = fast->next;
    		} else {
    			end_in_middle = true;
    		}
    	}
    	if(!end_in_middle) {
    		slow = slow->next;
    	}
    	
    	// reverse slow, and fast is the new head for the second half
    	fast = nullptr;
    	ListNode *p = nullptr;
    	while(slow != nullptr) {
    		p = slow->next;
    		slow->next = fast;
    		fast = slow;
    		slow = p;
    	}

    	// check if it's palindrome
    	while(fast != nullptr) {
    		if(fast->val != he->val)
    			return false;
    		fast = fast->next;
    		he = he->next;
    	}
    	return true;
    }
};
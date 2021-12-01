// C++
// leetcode 92
// https://leetcode-cn.com/problems/reverse-linked-list-ii/
// 不移动结点之间的关系，只修改所涉及的结点的值

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    	if(left == right)
    		return	head;
    	right = right - left + 1;
    	int tmp[right];
    	ListNode* res = head;
    	while(left > 1) {
    		head = head -> next;
    		left--;
    	}

    	ListNode* mark = head;
    	// 录入tmp
    	for(int i = 0; i < right; i++) {
    		tmp[i] = head -> val;
    		head = head -> next;
    	}

    	// 录回去
    	for(int i = right - 1; i >= 0; i--) {
    		mark -> val = tmp[i];
    		mark = mark -> next;
    	}

    	return	res;
    }
};
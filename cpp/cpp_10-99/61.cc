// C++
// leetcode 61
// https://leetcode-cn.com/problems/rotate-list/
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
	ListNode* end_;
	int getLength(ListNode* head) {
		// 得到长度同时设置 end_
		int length = 0;
		while(head -> next != nullptr) {
			length++;
			head = head ->next;
		}
		end_ = head;
		return	length + 1;
	}

	ListNode* getNth(ListNode* head, int a) {
		while(a > 1) {
			head = head -> next;
            a--;
        }
		return	head;
	}

    ListNode* rotateRight(ListNode* head, int k) {
    	if(head == nullptr)
            return head;
    	int n = getLength(head);	// 同时 end_ 也设置完毕
    	k %= n;
    	if(k == 0)
    		return	head;
    	end_ -> next = head;
    	head = getNth(head, n - k);
    	ListNode* res = head -> next;
    	head->next = nullptr;
    	return	res;
    }
};
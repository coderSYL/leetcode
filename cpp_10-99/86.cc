// C++
// leetcode 86
// https://leetcode-cn.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
    	if(!head)	return	nullptr;
    	vector<int> small;
    	vector<int> big;
    	ListNode* p = head;
    	while(p) {
    		if(p -> val < x)
    			small.push_back(p -> val);
    		else
    			big.push_back(p -> val);
    		p = p -> next;
    	}
    	p = head;
    	for(auto a : small) {
    		p -> val = a;
    		p = p -> next;
    	}
        for(auto a : big) {
    		p -> val = a;
    		p = p -> next;
    	}
    	return	head;
    }
};
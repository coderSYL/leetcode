/*
 * C++
 * leetcode2
 * url: https://leetcode-cn.com/problems/add-two-numbers/
 */

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
	bool IsZero(ListNode* l){	//判断以l为头的链表是否为0
		if(l->val ==0 && l->next==nullptr)
			return true;
		return false;
	}

	int getlength(ListNode* l1){	// 得到链表的长度
		int res = 0;
		while(l1 !=nullptr){
			l1 = l1->next;
			res++;
		}
		return res;
	}

	ListNode* nNode(int num){	// 得到长为num的都为0的链表
		if(num ==1)
			return new ListNode();
		ListNode* res = new ListNode(0, nNode(num-1));
		return res;
	}

	ListNode* GetNthNode(ListNode* l, int n){	//得到第n个结点的指针
		int i = 1;
		while(i<n){
			i++;
			l = l->next;
		}
		return l;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(IsZero(l1))
        	return l2;
        if(IsZero(l2))
        	return l1;

        int len1 = getlength(l1), len2 = getlength(l2);
        if(len1!=len2){	// 处理不同长的情况，将两链表长度对齐
        	int min, max;
	       	ListNode* minp;
	        if(len2 > len1){
	        	minp = l1;
	        	min = len1;
	        	max = len2;
	        }else{
	        	minp = l2;
	        	min = len2;
	        	max = len1;
	        }
	        minp = GetNthNode(minp, min);
	        minp ->next = nNode(max-min);
	        len1 = max;
	        len2 = max;
        }
        ListNode* head = l1;
        
        int count =1,temp;	
        bool flag=false;
        while(count<len1){
        	temp = l1->val + l2->val;
        	if(flag)
        		temp++;
        	if(temp/10>0){
        		flag = true;
        		temp = temp%10;
        	}
        	else
        		flag = false;
        	l1->val = temp;
        	count++;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        temp = l1->val + l2->val;
    	if(flag)
    		temp++;
    	if(temp/10>0){
    		flag = true;
    		temp = temp%10;
    	}
    	else
    		flag = false;
        l1->val = temp;
    	if(flag)
    		l1->next = new ListNode(1);
    	return head;
    }
};
// C++
// leetcode 24
// url: https://leetcode-cn.com/problems/swap-nodes-in-pairs/
// 思路:
// 把所有指针装进一个数组，然后交换相邻两个指针在数组中的位置，然后连起来

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
    ListNode* swapPairs(ListNode* head) {
        // list of size 0
        if(head ==nullptr)
            return nullptr;
        // maximum 100 nodes
        ListNode* temp[101];
        ListNode* p = head;
        int size = 0;
        // put pointer into temp[]
        while(p !=nullptr)
        {
            temp[size] = p;
            size++;
            p = p->next;
        }
        int i =0;
        // do the swap
        while(i<size){
            if(i+1 ==size)
                break;
            p = temp[i];
            temp[i] =temp[i+1];
            temp[i+1] = p;
            i +=2;
        }
        // link the nodes
        i=0;
        while(i<size-1){
            temp[i]->next = temp[i+1];
            i++;
        }
        // tail of the list points to nullptr
        temp[i]->next = nullptr;
        return temp[0];
    }
};
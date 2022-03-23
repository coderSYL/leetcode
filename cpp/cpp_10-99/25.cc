// C++
// leetcode 25
// url: https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
// 思路:
// 用一个长度为k的指针数组来装指针，每次翻转k个值

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        head = nullptr;
        ListNode* this_head= nullptr;
        ListNode* this_end = nullptr;
        ListNode* changeArea[k];
        while(true)
        {
            int i = 0;
            this_head = p;
            while(i<k && p!=nullptr)
            {
                // 装入数组
                changeArea[i] = p;
                p= p->next;
                i++;
            }
            if(i<k)
            {
                // 没装满，no need to reverse
                if(this_end == nullptr)
                {
                    return this_head;
                }
                else
                {
                    this_end->next = this_head;
                    return head;
                }
            }
            // need to reverse
            i = k-1;
            while(i>0)
            {   
                // link
                changeArea[i]->next = changeArea[i-1];
                i--;
            }

            if(head==nullptr)
            {   
                // 无 global head时，确定global head
                head = changeArea[k-1];
            }
            else
            {
                // 有global head时，把上一组翻转后的结尾与这一组翻转后的头链接起来
                this_end->next = changeArea[k-1];
            }
            this_end = changeArea[0];   // 留下这组的尾巴，给下一组使用
        }
        return head;    // 正常情况，不会从这个地方返回
    }
};
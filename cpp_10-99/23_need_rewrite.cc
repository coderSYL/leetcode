// C++
// leetcode 23
// url: https://leetcode-cn.com/problems/merge-k-sorted-lists/
// 思路:
// 预处理，删除所有空指针
// 每次循环找到下一个结点，把它接上
// 若那个结点是尾结点，则在lists中删除它
// 若不是，用它的next替代它在lists中的位置

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ret_head=nullptr;
        ListNode* ret_end = nullptr;
        for(int i = lists.size()-1; i>=0; i--)
        {
            if(lists[i] == nullptr)
                lists.erase(lists.begin()+i);
        }   // delete all nullptr in lists

        while(!lists.empty())
        {
            ListNode* tobeLinked = nullptr;
            int minThisLoop = INT_MAX;
            int index = -1;
            for(int i =lists.size()-1; i>=0; i--)
            {
                if(lists[i]->val < minThisLoop)
                {
                    index = i;
                    tobeLinked = lists[i];
                    minThisLoop = tobeLinked->val;
                }
            }   // determinate next pointer

            if(ret_end==nullptr)
            {   // no head, fill it
                ret_head = tobeLinked;
                ret_end  = tobeLinked;
            }
            else
            {   
                ret_end->next = tobeLinked;
                ret_end = tobeLinked;
            }

            if(tobeLinked->next ==nullptr)
            {
                lists.erase(lists.begin() +index);
            }
            else
            {
                lists[index] =  tobeLinked->next;
            }
        }
        return ret_head;
    }
};
// C++
// leetcode 725
// https://leetcode-cn.com/problems/split-linked-list-in-parts/
// 遍历链表把指针装进一个vector里，然后直接找到答案

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>   tmp;
        while(head != nullptr) {
            tmp.push_back(head);
            head = head->next;
        }
        int n = tmp.size();
        int avg = n / k;
        int rest = n % k;
        vector<ListNode*>   res;
        bool outOfRange = false;
        int now = 0;
        while(k > 0) {
            if(outOfRange) {
                res.push_back(nullptr);
                k--;
                continue;
            }

            if(now >= n) {
                outOfRange = true;
                continue;
            }

            res.push_back(tmp[now]);
            if(now != 0) {
                tmp[now-1]->next = nullptr;
            }
            k--;
            now += avg;
            if(rest > 0) {
                now++;
                rest--;
            }
        }
        return  res;
    }
};
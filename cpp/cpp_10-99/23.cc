// C++
// leetcode 23
// https://leetcode-cn.com/problems/merge-k-sorted-lists/
// 思路:
// 预处理，把所有非空头指针录入优先队列，排列方法按节点val从小到大
// 每次处理一个节点p，先取出并接到当前节点cur的下一个上，若p的下一节点非空，把下一节点加入优先队列，然后p变成cur

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
    struct Node{
        ListNode *p;
        Node(ListNode* p) : p(p) {}
        // 小顶堆的排序： 高度从小到大排列
        bool operator<(const Node& a) const {
        return p->val > a.p->val;
        }
    };

    priority_queue<Node> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto x : lists) {
            if(x != nullptr)
                q.push(Node(x));
        }

        if(q.empty())
            return  nullptr;

        ListNode* res = q.top().p, *cur = res;
        q.pop();
        if(cur -> next != nullptr)
            q.push(Node(cur -> next));

        while(!q.empty()) {
            cur -> next = q.top().p;
            q.pop();
            cur = cur -> next;
            if(cur -> next != nullptr)
                q.push(Node(cur  -> next));
        }

        return res;
    }
};
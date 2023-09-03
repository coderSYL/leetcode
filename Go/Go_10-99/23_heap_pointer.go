// Go
// leetcode 23
// https://leetcode.cn/problems/merge-k-sorted-lists/

import (
	"container/heap"
)

type Heap []*ListNode

func (h Heap) Len() int { return len(h) }

// 名为 Less，实为 Greater
func (h Heap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h Heap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *Heap) Push(x interface{}) {
	*h = append(*h, x.(*ListNode))
}

func (h *Heap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func mergeKLists(lists []*ListNode) *ListNode {
	h := &Heap{}
	for _, p := range lists {
		if p != nil {
			heap.Push(h, p)
		}
	}
	var res *ListNode = nil
	var tail *ListNode = nil
	update := func(p *ListNode) {
		if res == nil {
			res = p
			tail = p
			tail.Next = nil
			return
		}

		tail.Next = p
		tail = p
		tail.Next = nil
	}

	for h.Len() != 0 {
		cur := heap.Pop(h).(*ListNode)
		if cur.Next != nil {
			heap.Push(h, cur.Next)
		}
		update(cur)
	}
	return res
 }
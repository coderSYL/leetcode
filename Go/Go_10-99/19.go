// Go
// leetcode 19
// https://leetcode.cn/problems/remove-nth-node-from-end-of-list/

/**
* Definition for singly-linked list.
* type ListNode struct {
*     Val int
*     Next *ListNode
* }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	sz := 0
	p := head
	for p != nil {
		sz++
		p = p.Next
	}

	if n == sz {
		return head.Next
	}
	n = sz - n - 1
	p = head
	for n > 0 {
		p = p.Next
		n--
	}
	p.Next = p.Next.Next
	return head
}
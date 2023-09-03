// Go
// leetcode 24
// https://leetcode.cn/problems/swap-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	first, second, third := head, head.Next, head.Next.Next
	second.Next = first
	first.Next = swapPairs(third)
	return second
}
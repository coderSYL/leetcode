// Go
// leetcode 143
// https://leetcode.cn/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func reorderList(head *ListNode)  {
	one, two:= head, head
	for two != nil {
		two= two.Next
		if two != nil {
			two = two.Next
			one = one.Next
		}
		
	}
	mid := one // 中间位置标记
	var head2 *ListNode = nil
	for one != nil {
		one.Next, one, head2 = head2, one.Next, one
	}
	one, two = head, head2
	for one != mid {
		one.Next, two.Next, one, two = two, one.Next, one.Next, two.Next	
	}
	one.Next = nil
 }
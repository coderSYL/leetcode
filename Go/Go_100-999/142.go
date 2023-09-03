// Go
// leetcode 142
// https://leetcode.cn/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 若有环，设非环长度为 a，慢指针相遇时走了环的长度为 b，环剩余长度为 c
// 则有 2 * (a + b) = a + b + k * (b + c) ，快指针比慢指针多转 k 圈
// 化简得， a - c = (k - 1) * (b + c)
// 此时若慢指针与头指针同时开始走，终将在环的入口相遇

func detectCycle(head *ListNode) *ListNode {
	one, two := head, head
	for two != nil {
		one = one.Next
		two = two.Next
		if two == nil {
			return nil
		}
		two = two.Next
		if one == two { // 有环
			for head != one {
				one = one.Next
				head = head.Next
			}
			return one
		}
	}
	return nil
}
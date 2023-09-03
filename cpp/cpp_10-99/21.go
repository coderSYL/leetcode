// Go
// leetcode 21
// https://leetcode.cn/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) (res *ListNode) {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}

	tail := res
	for list1 != nil && list2 != nil {
		if list1.Val < list2.Val {
			if res == nil { // 第一个节点
				res = list1
				tail = list1
				list1 = list1.Next
				// tail.Next = nil
				continue
			}
			// 尾插法
			tail.Next = list1
			list1 = list1.Next
			tail = tail.Next
			// tail.Next = nil
			continue
		}
		if res == nil { // // 第一个节点
			res = list2
			tail = list2
			list2 = list2.Next
			// tail.Next = nil
			continue
		}
		// 尾插法
		tail.Next = list2
		list2 = list2.Next
		tail = tail.Next
		// tail.Next = nil
	}
	if list1 != nil {
		tail.Next = list1
	}
	if list2 != nil {
		tail.Next = list2
	}
	return res
}
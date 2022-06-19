// Go
// leetcode 2
// https://leetcode.cn/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1.Next == nil && l1.Val == 0 {
		return l2
	}
	if l2.Next == nil && l2.Val == 0 {
		return l1
	}
	carry := false

	l1.Val += l2.Val
	if(l1.Val >= 10) {
		l1.Val %= 10
		carry = true
	}
	res, p, sum := l1, l1, 0
	l1 = l1.Next
	l2 = l2.Next
	for l1 != nil || l2 != nil || carry {
		if carry {
			carry = false
			sum = 1
		} else {
			sum = 0
		}

		if l1 != nil {
			sum += l1.Val
			p.Next = l1
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			p.Next = l2
			l2 = l2.Next
		}
		if p.Next == nil {
            tmp := &ListNode{}
			p.Next = tmp
		}
		p = p.Next
		if(sum >= 10) {
			sum %= 10
			carry = true
		}
		p.Val = sum
	}
	p.Next = nil
	return res
}
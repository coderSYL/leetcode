// Go
// leetcode 1171
// https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeZeroSumSublists(head *ListNode) *ListNode {
	stk := []int{0}
	p := head
	for p != nil {
		curSum := stk[len(stk)-1] + p.Val
		pre := -1
		for i, v := range stk {
			if v == curSum {
				pre = i
				break
			}
		}
		switch pre {
		case 0: // 前面全截掉
			head = p.Next
			stk = stk[:1]
		case -1: // 无和为0，添加至
			stk = append(stk, curSum)
		default: // 保留前 pre 个
			stk = stk[:pre+1]
			preCutNode := getNth(head, pre)
			preCutNode.Next = p.Next
		}
		p = p.Next
	}
	return head
}

func getNth(head *ListNode, n int) *ListNode {
	for n > 1 {
		n--
		head = head.Next
	}
	return head
}
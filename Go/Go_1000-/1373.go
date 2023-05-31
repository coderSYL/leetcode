// Go
// leetcode 1373
// https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxSumBST(root *TreeNode) (res int) {
	var getSumIfBinary func(p *TreeNode) (int, int, int, bool)
	getSumIfBinary = func(p *TreeNode) (sum, big, small int, ok bool) { // 不允许空节点
		big, small, ok = p.Val, p.Val, true
		if p.Left != nil {
			l, bigL, smallL, leftOk := getSumIfBinary(p.Left)
			if !leftOk || bigL >= p.Val {
				ok = false
			} else {
				small = min(smallL, small)
				sum += l
			}
		}

		if p.Right != nil {
			r, bigR, smallR, rightOk := getSumIfBinary(p.Right)
			if !rightOk || smallR <= p.Val {
				ok = false
			} else {
				big = max(big, bigR)
				sum += r
			}
		}

		sum += p.Val
		if !ok {
			return 0, 0, 0, false
		}
		res = max(res, sum)
		return sum, big, small, true
	}

	getSumIfBinary(root)
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
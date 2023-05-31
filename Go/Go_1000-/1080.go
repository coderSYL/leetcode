// Go
// leetcode 1080
// https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sufficientSubset(root *TreeNode, limit int) *TreeNode {
	var helper func(int, *TreeNode) bool
	helper = func(preSum int, p *TreeNode) bool {
		preSum += p.Val
		if p.Left == nil && p.Right == nil {
			return preSum >= limit
		}
		ok := false
		if p.Left != nil {
			if helper(preSum, p.Left) {
				ok = true
			} else {
				p.Left = nil
			}
		}

		if p.Right != nil {
			if helper(preSum, p.Right) {
				ok = true
			} else {
				p.Right = nil
			}
		}
		return ok
	}
	if helper(0, root) {
		return root
	} else {
		return nil
	}
}
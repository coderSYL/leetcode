// Go
// leetcode 1026
// https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxAncestorDiff(root *TreeNode) (res int) {
	var dfs func(int, int, *TreeNode)
	dfs = func(small int, big int, p *TreeNode) {
		if p == nil {
			return
		}
		big = max(big, p.Val)
		small = min(small, p.Val)
		res = max(res, big-small)
		dfs(small, big, p.Left)
		dfs(small, big, p.Right)
	}
	dfs(root.Val, root.Val, root)
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
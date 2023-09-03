// Go
// leetcode 1448
// https://leetcode.cn/problems/count-good-nodes-in-binary-tree/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func goodNodes(root *TreeNode) int {
	var dfs func(*TreeNode, int) int
	dfs = func(p *TreeNode, x int) int {
		if p== nil {
			return 0
		}
		nextX := max(x, p.Val)
		res := dfs(p.Left, nextX) + dfs(p.Right, nextX)
		if p.Val >= x {
			res++
		}
		return res
	}
	return dfs(root, -1000_000)
 }

 func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
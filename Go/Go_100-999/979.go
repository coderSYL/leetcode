// Go
// leetcode 979
// https://leetcode.cn/problems/distribute-coins-in-binary-tree/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func distributeCoins(root *TreeNode) int {
	res := 0

	var dfs func(*TreeNode) int
	dfs = func(p *TreeNode) int {
		if p == nil {
			return 0
		}
		l := dfs(p.Left)
		r := dfs(p.Right)
		l_abs := abs(l)
		r_abs := abs(r)
		res += l_abs + r_abs
		return l + r + p.Val - 1
	}

	dfs(root)
	return res
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
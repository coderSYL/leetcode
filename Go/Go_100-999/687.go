// Go
// leetcode 687
// https://leetcode.cn/problems/longest-univalue-path/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestUnivaluePath(root *TreeNode) int {
	res := 0
	dfs(root, &res)
	return res
}

func dfs(p *TreeNode, res *int) int {
	if p == nil {
		return 0
	}

	l, r := dfs(p.Left, res), dfs(p.Right, res)
	if p.Left != nil && p.Left.Val == p.Val {
		l++
	} else {
		l = 0
	}
	if p.Right != nil && p.Right.Val == p.Val {
		r++
	} else {
		r = 0
	}

	if *res < l+r {
		*res = l + r
	}

	if l > r {
		return l
	}
	return r
}
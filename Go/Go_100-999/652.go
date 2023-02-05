// Go
// leetcode 652
// https://leetcode.cn/problems/find-duplicate-subtrees/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import (
	"strconv"
)

func findDuplicateSubtrees(root *TreeNode) (res []*TreeNode) {
	var cnt = make(map[string]int)

	var dfs func(p *TreeNode) string
	dfs = func(p *TreeNode) string {
		// 返回 以结点 p 为根结点的树的结构为特征的一个值
		if p == nil {
			return " "
		}

		key := ""
		key += strconv.Itoa(p.Val) + "_" + dfs(p.Left) + dfs(p.Right)
		cnt[key]++
		if cnt[key] == 2 {
			res = append(res, p)
		}
		return key
	}

	dfs(root)
	return res
}
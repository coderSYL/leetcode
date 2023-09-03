// Go
// leetcode 257
// https://leetcode.cn/problems/binary-tree-paths/description/

import (
	"strconv"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func binaryTreePaths(root *TreeNode) (res []string) {
	stk := []*TreeNode{root}
	Pop := func() *TreeNode {
		n := len(stk)
		ret := stk[n-1]
		stk = stk[:n-1]
		return ret
	}

	GetTop := func() *TreeNode { return stk[len(stk)-1] }

	updateRes := func() {
		s := strconv.Itoa(stk[0].Val)
		for i := 1; i < len(stk); i++ {
			s += "->" + strconv.Itoa(stk[i].Val)
		}
		res = append(res, s)
	}

	var pre *TreeNode
	for len(stk) != 0 {
		p := GetTop()
		if p.Left == nil && p.Right == nil { // 叶子结点
			updateRes()
			pre = Pop()
			continue
		}
		if pre != nil && pre == p.Right { // 子节点都搞过了
			pre = Pop()
			continue
		}

		if p.Left != nil && pre != p.Left { // 左边没搞过
			stk = append(stk, p.Left)
			continue
		}

		if p.Right != nil && pre != p.Right { // 右边没搞过
			stk = append(stk, p.Right)
			continue
		}
		pre = Pop()
	}
	return res
}
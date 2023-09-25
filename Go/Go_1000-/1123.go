// Go
// leetcode 1123
// https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type a struct {
	p *TreeNode
	u int
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	q := []*a{&a{root, 1}}
	haveNext := false
	if root.Left != nil || root.Right != nil {
		haveNext = true
	}
	lvl := 1
	nextQ := []*a{}
	for haveNext { // bfs with queue
		lvl++
		haveNext = false
		for _, x := range q {
			p, u := x.p, x.u
			if p.Left != nil {
				haveNext = haveNext || haveSon(p.Left)
				nextQ = append(nextQ, &a{p.Left, u * 2})
			}
			if p.Right != nil {
				haveNext = haveNext || haveSon(p.Right)
				nextQ = append(nextQ, &a{p.Right, u*2 + 1})
			}
		}
		q, nextQ = nextQ, q
		nextQ = nextQ[:0]
	}
	sz := len(q)

	small := q[0].u // 最左边与最右边序列号
	big := q[sz-1].u

	for small != big {
		small /= 2
		big /= 2
	}

	helper := 1
	for small != 1 {
		helper = 2*helper + small%2
		small /= 2
	}
	p := root
	for helper != 1 {
		cur := helper % 2
		helper /= 2
		if cur == 0 {
			p = p.Left
		}
		if cur == 1 {
			p = p.Right
		}
	}

	return p
}

func haveSon(p *TreeNode) bool {
	return p.Left != nil || p.Right != nil
}

// level 1
// 1

// lvl 2
// 2 3
// [2^(n-1), 2^n)
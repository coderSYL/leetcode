// Go
// leetcode 655
// https://leetcode.cn/problems/print-binary-tree/

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

func printTree(root *TreeNode) [][]string {
	depth, m := 0, 1
	q_p := []*TreeNode{root}

	// find depth
	for len(q_p) != 0 {
		depth++
		size := len(q_p)
		for i := 0; i < size; i++ {
			if q_p[i].Left != nil {
				q_p = append(q_p, q_p[i].Left)
			}
			if q_p[i].Right != nil {
				q_p = append(q_p, q_p[i].Right)
			}
		}
		q_p = q_p[size : ]
	}
	m <<= depth

	// preteatment for res
	res := make([][]string, depth)
	for i := 0; i < depth; i++ {
		res[i] = make([]string, m - 1)
	}

	// fill res
	q_p = append(q_p, root)
	q_idx := []int{(m - 2) / 2}
	level, d := 0, m >> 2
	for len(q_p) != 0 {
		size := len(q_p)

		for i := 0; i < size; i++ {
			res[level][q_idx[i]] = strconv.Itoa(q_p[i].Val)
			if q_p[i].Left != nil {
				q_p = append(q_p, q_p[i].Left)
				q_idx = append(q_idx, q_idx[i] - d)
			}
			if q_p[i].Right != nil {
				q_p = append(q_p, q_p[i].Right)
				q_idx = append(q_idx, q_idx[i] + d)
			}
		}
		level++
		d >>= 1
		q_p = q_p[size : ]
		q_idx = q_idx[size : ]
	}

	return res
}
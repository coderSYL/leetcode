// Go
// leetcode 1161
// https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func maxLevelSum(root *TreeNode) int {
	sum := make([]int, 10)
	q := []*TreeNode{root}
	level := 1
	for len(q) != 0 {
		for len(sum) - 1 < level {
			sum = append(sum, 0)
		}

		size := len(q)

		for i := 0; i < size; i++ {
			sum[level] += q[i].Val

			if q[i].Left != nil {
				q = append(q, q[i].Left)
			}

			if q[i].Right != nil {
				q = append(q, q[i].Right)
			}
		}

		q = q[size : ]

		level++
	}

	res := 1
	for i := 2; i < level; i++ {
		if sum[i] > sum[res] {
			res = i
		}
	}

	return res
}
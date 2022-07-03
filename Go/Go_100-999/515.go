// Go
// leetcode 515
// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func largestValues(root *TreeNode) (res []int) {
	if root == nil {
		return res
	}
	q := []*TreeNode{root}
	for len(q) != 0 {
		size, max := len(q), q[0].Val
		for i := 0; i < size; i++ {
			if q[i].Val > max {
				max = q[i].Val
			}
			if q[i].Left != nil {
				q = append(q, q[i].Left)
			}
			if q[i].Right != nil {
				q = append(q, q[i].Right)
			}
		}
		res = append(res, max)
		q = q[size : ]
	}
	return res
}
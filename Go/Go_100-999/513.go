// Go
// leetcode 513
// https://leetcode.cn/problems/find-bottom-left-tree-value/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findBottomLeftValue(root *TreeNode) (res int) {
	q := []*TreeNode{root}
	for len(q) != 0 {
		res = q[0].Val
		size := len(q)
		for i := 0; i < size; i++ {
			node := q[i]
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		q = q[size:]
	}
	return res
}
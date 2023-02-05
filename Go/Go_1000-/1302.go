// Go
// leetcode 1302
// https://leetcode.cn/problems/deepest-leaves-sum/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func deepestLeavesSum(root *TreeNode) int {
	q := []*TreeNode{root}
	var sum int
	for len(q) != 0 {
		sz := len(q)
		sum = 0
		for i := 0; i < sz; i++ {
			sum += q[i].Val
			if q[i].Left != nil {
				q = append(q, q[i].Left)
			}
			if q[i].Right != nil {
				q = append(q, q[i].Right)
			}
		}
		q = q[sz:]
	}
	return sum
}
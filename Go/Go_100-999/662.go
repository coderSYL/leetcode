// Go
// leetcode 662
// https://leetcode.cn/problems/maximum-width-of-binary-tree/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func widthOfBinaryTree(root *TreeNode) (res int) {
	q := []*TreeNode{root}
	idxs := []int{1}
	for len(q) != 0 {
		size := len(q)
		mn := idxs[0]
		if idxs[size-1]-idxs[0]+1 > res {
			res = idxs[size-1] - idxs[0] + 1
		}
		for i := 0; i < size; i++ {
			if q[i].Left != nil {
				q = append(q, q[i].Left)
				idxs = append(idxs, (idxs[i]-mn)*2)
			}
			if q[i].Right != nil {
				q = append(q, q[i].Right)
				idxs = append(idxs, (idxs[i]-mn)*2+1)
			}
		}
		q = q[size:]
		idxs = idxs[size:]
	}
	return res
}
// Go
// leetcode 2236
// https://leetcode.cn/problems/root-equals-sum-of-children/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func checkTree(root *TreeNode) bool {
	lval, rval := root.Left.Val, root.Right.Val
	return root.Val == lval + rval
}
// Go
// leetcode 814
// https://leetcode.cn/problems/binary-tree-pruning/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pruneTree(root *TreeNode) *TreeNode {
	if root.Left != nil {
		root.Left = pruneTree(root.Left)
	}

	if root.Right != nil {
		root.Right = pruneTree(root.Right)
	}

	if root.Left == nil && root.Right == nil && root.Val == 0 {
		return nil
	}

	return root
}
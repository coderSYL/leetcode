// Go
// leetcode 617
// https://leetcode.cn/problems/merge-two-binary-trees/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	if root1 == nil && root2 == nil {
		return nil
	}
	if root1 == nil {
		return root2
	}
	if root2 == nil {
		return root1
	}

	cur := &TreeNode{root1.Val + root2.Val, nil, nil}
	cur.Left = mergeTrees(root1.Left, root2.Left)
	cur.Right = mergeTrees(root1.Right, root2.Right)
	return cur
 }
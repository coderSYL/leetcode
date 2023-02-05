// Go
// leetcode 623
// https://leetcode.cn/problems/add-one-row-to-tree/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func addOneRow(root *TreeNode, val int, depth int) *TreeNode {
	if depth == 1 {
		return &TreeNode{val, root, nil}
	}

	dfs(root, 1, val, depth)

	return root
}

func dfs(p *TreeNode, cur, val, depth int) {
	if cur >= depth {
		return
	}

	if cur+1 == depth {
		p.Left = &TreeNode{val, p.Left, nil}
		p.Right = &TreeNode{val, nil, p.Right}
		return
	}

	if p.Left != nil {
		dfs(p.Left, cur+1, val, depth)
	}

	if p.Right != nil {
		dfs(p.Right, cur+1, val, depth)
	}
}
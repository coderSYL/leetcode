// Go
// leetcode 1145
// https://leetcode.cn/problems/binary-tree-coloring-game/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// 计算以 p 为根节点的树的结点数
func count(p *TreeNode) int {
	if p == nil {
		return 0
	}
	res := 1 + count(p.Left) + count(p.Right)
	return res
}

// 寻找在以 root 为根的树中，寻找值为 t 的节点
func search(root *TreeNode, t int) (res *TreeNode) {
	if root == nil {
		return nil
	}
	if root.Val == t {
		return root
	}
	res = search(root.Left, t)
	if res != nil {
		return res
	}
	res = search(root.Right, t)
	return res
}

func btreeGameWinningMove(root *TreeNode, n int, x int) bool {
	nodeX := search(root, x)
	// fmt.Println(nodeX)
	l := count(nodeX.Left)
	if l > n/2 {
		return true
	}

	r := count(nodeX.Right)
	if r > n/2 {
		return true
	}

	up := n - 1 - l - r
	if up > n/2 {
		return true
	}
	return false
}
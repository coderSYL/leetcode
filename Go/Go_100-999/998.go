// Go
// leetcode 998
// https://leetcode.cn/problems/maximum-binary-tree-ii/
// 1. 若A为空，则返回 val 值的结点的指针
// 2. 若根的值比 val 小，则新结点为根，原根变为左子树
// 3. 若根的值比 val 大
//		1)若A非空，从右子树找下去，直到找到某个值大于val且右子树的值小于
// 	  	  val的结点将新结点插入到右子树，新结点的左子树插上原先的右子树
// 	  	2)若找不到这种右子树，则在最后一个结点的空的右子树上插入新结点


/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func findParentForNewNode(p *TreeNode, val int) *TreeNode {
	if p == nil || p.Val < val {
		return nil
	}

	if p.Right == nil || p.Right.Val < val {
		return p
	}

	return findParentForNewNode(p.Right, val)
}

func insertIntoMaxTree(root *TreeNode, val int) *TreeNode {
	p := findParentForNewNode(root, val)
	if p == nil {
		return &TreeNode{val, root, nil}
	} else {
		p.Right = &TreeNode{val, p.Right, nil}
	}
	return root
}
// Go
// leetcode 1110
// https://leetcode.cn/problems/delete-nodes-and-return-forest/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func delNodes(root *TreeNode, to_delete []int) (res []*TreeNode) {
	queueForNoParent := []*TreeNode{root}
	isBad := make([]bool, 1001)
	for _, x := range to_delete {
		isBad[x] = true
	}

	var dfs func(*TreeNode)
	dfs = func(p *TreeNode) { // p must be good
		if p.Left != nil {
			if isBad[p.Left.Val] {
				queueForNoParent = append(queueForNoParent, p.Left)
				p.Left = nil
			} else {
				dfs(p.Left)
			}
		}
		if p.Right != nil {
			if isBad[p.Right.Val] {
				queueForNoParent = append(queueForNoParent, p.Right)
				p.Right = nil
			} else {
				dfs(p.Right)
			}
		}

	}

	for len(queueForNoParent) > 0 {
		cur := queueForNoParent[len(queueForNoParent)-1]
		queueForNoParent = queueForNoParent[:len(queueForNoParent)-1]
		if isBad[cur.Val] {
			if cur.Left != nil {
				queueForNoParent = append(queueForNoParent, cur.Left)
				cur.Left = nil
			}

			if cur.Right != nil {
				queueForNoParent = append(queueForNoParent, cur.Right)
				cur.Right = nil
			}
			continue
		} else {
			res = append(res, cur)
		}
		dfs(cur)
	}
	return res
}
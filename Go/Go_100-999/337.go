// Go
// leetcode 337
// https://leetcode.cn/problems/house-robber-iii/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func rob(root *TreeNode) int {
	take, not := dfs(root)
	return max(take, not)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func dfs(p *TreeNode) (int, int) {
	if p == nil {
		return 0, 0
	}
	
	Take, notTake := p.Val, 0
	lS, lnotS := dfs(p.Left)
	rS, rnotS := dfs(p.Right)
	Take += lnotS + rnotS
	notTake += max(lS, lnotS) + max(rS, rnotS)
	return Take, notTake
}
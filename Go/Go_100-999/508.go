// Go
// leetcode 508
// https://leetcode.cn/problems/most-frequent-subtree-sum/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func getTreeSum(t *TreeNode, cnt map[int]int) int {
	// t is not nil
	res := t.Val
	if t.Left != nil {
		res += getTreeSum(t.Left, cnt)
	}
	if t.Right != nil {
		res += getTreeSum(t.Right, cnt)
	}
	cnt[res]++
	return res
}

func findFrequentTreeSum(root *TreeNode) []int {
	m, cur, res := map[int]int{}, 0, []int{}
	getTreeSum(root, m)
	for k, v := range m {
		if v > cur {
			res = []int{k}
			cur = v
			// fmt.Println("inti", k)
		} else if v == cur {
			res = append(res, k)
			// fmt.Println("add", k)
		}
	}
	return res
}
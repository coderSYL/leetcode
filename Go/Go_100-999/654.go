// Go
// leetcode 654
// https://leetcode.cn/problems/maximum-binary-tree/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func constructMaximumBinaryTree(nums []int) *TreeNode {
	var hepler func(arr []int, l, r int) *TreeNode
	hepler = func(arr []int, l, r int) *TreeNode {
		// 返回空指针
		if l > r {
			return nil
		}
		// 找到 [l, r] 范围内最大值
		mx, p := -1, -1
		for i := l; i <= r; i++ {
			if arr[i] > mx {
				mx = arr[i]
				p = i
			}
		}

		return &TreeNode{mx, hepler(arr, l, p-1), hepler(arr, p+1, r)}
	}

	return hepler(nums, 0, len(nums)-1)
}
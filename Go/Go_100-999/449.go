// Go
// leetcode 449
// https://leetcode.cn/problems/serialize-and-deserialize-bst/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import "strconv"

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	return code(root)
}

func code(root *TreeNode) string {
	if root == nil {
		return "n"
	}
	num := strconv.Itoa(root.Val)
	return "(" + code(root.Left) + "!" + num + "!" + code(root.Right) + ")"
}

func decode(data string, l, r int) *TreeNode {
	if data[l] == 'n' {
		return nil
	}
	cnt := 0
	L := -1
	R := -1
	i := l
	for i = l; i <= r; i++ {
		switch data[i] {
		case '(':
			cnt++
		case ')':
			cnt--
		case '!':
			if cnt == 1 {
				if L < 0 {
					L = i
				} else {
					R = i
					break
				}
			}
		}
	}
	n, _ := strconv.Atoi(data[L+1 : R])
	var root *TreeNode = &TreeNode{n, nil, nil}
	root.Left = decode(data, l+1, L-1)
	root.Right = decode(data, R+1, r-1)
	return root
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	return decode(data, 0, len(data)-1)
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor()
 * deser := Constructor()
 * tree := ser.serialize(root)
 * ans := deser.deserialize(tree)
 * return ans
 */
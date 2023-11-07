// Go
// leetcode 117
// https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

 func connect(root *Node) *Node {
	nextFirst := root
	for nextFirst != nil {
		nextFirst = helper(nextFirst)
	}
	return root
 }

func helper(p *Node) *Node {// return nextFirst
	if p == nil {
		return nil
	}
	if p.Left != nil && p.Right != nil {
		p.Left.Next = p.Right
		p.Right.Next = getNext(p.Next)
		helper(p.Next)
		return p.Left
	}

	if p.Left != nil {
		p.Left.Next = getNext(p.Next)
		helper(p.Next)
		return p.Left
	}

	if p.Right != nil {
		p.Right.Next = getNext(p.Next)
		helper(p.Next)
		return p.Right
	}

	return helper(p.Next)
}

func getNext(x *Node) *Node{
	for x != nil {
		if x.Left != nil {
			return x.Left
		}
		if x.Right != nil {
			return x.Right
		}
		x = x.Next
	}
	return nil
}
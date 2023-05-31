// Go
// leetcode 138
// https://leetcode-cn.com/problems/copy-list-with-random-pointer/

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
	m := make(map[*Node]*Node)
	p := head
	for p != nil {
		m[p] = &Node{
			Val: p.Val,
		}
		p = p.Next
	}

	p = head
	for p != nil {
		newP := m[p]
		newP.Next = m[p.Next]
		newP.Random = m[p.Random]
		p = p.Next
	}
	return m[head]
}
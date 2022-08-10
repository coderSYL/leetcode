// Go
// leetcode 919
// https://leetcode.cn/problems/complete-binary-tree-inserter/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type CBTInserter struct {
	TreeSize int
	Root *TreeNode
}


func Constructor(root *TreeNode) CBTInserter {
	res := 0
	q := []*TreeNode{root}
	for len(q) != 0 {
		size := len(q)
		res += size
		if size * 2 - 1 != res {
			break
		}

		for i := 0; i < size; i++ {
			if q[i].Left != nil {
				q = append(q, q[i].Left)
			} else {
				break
			}
			if q[i].Right != nil {
				q = append(q, q[i].Right)
			} else {
				break
			}
		}
		q = q[size : ]
	}

	return CBTInserter{res, root}
}


func (this *CBTInserter) Insert(val int) int {
	this.TreeSize++
	curIdx, depth := this.TreeSize, 0
	for curIdx > 0 {
		curIdx >>= 1
		depth++
	}
	curIdx = this.TreeSize
	p := this.Root

	// find father of new TreeNode
	for i := depth - 2; i > 0; i-- {
		if ((curIdx >> i) & 1) == 0 {
			p = p.Left
		} else {
			p = p.Right
		}
	}

	if curIdx & 1 == 0 {
		p.Left = &TreeNode{val, nil, nil}
	} else {
		p.Right = &TreeNode{val, nil, nil}
	}

	return p.Val
}


func (this *CBTInserter) Get_root() *TreeNode {
	return this.Root
}


/**
 * Your CBTInserter object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Insert(val);
 * param_2 := obj.Get_root();
 */
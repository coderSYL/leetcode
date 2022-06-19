// Go
// leetcode offerII 029
// https://leetcode.cn/problems/4ueAj6/

/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 * }
 */

func putAfter(aNode, bNode *Node) {
	bNode.Next = aNode.Next
	aNode.Next = bNode
}

func insert(he *Node, x int) *Node {
	tmp := &Node{Val : x, }
	// from 0 to 1 Node
    if he == nil {
    	tmp.Next = tmp
    	return tmp
    }

    // get min and max from the linklist
    res, min, max, cur := he, 2_000_000, -2_000_000, 0
    for {
    	cur = he.Val
    	if cur < min {
    		min = cur
    	}
    	if cur > max {
    		max = cur
    	}
    	he = he.Next
    	if he == res {
    		break
    	}
    }

    if min == max {
    	putAfter(res, tmp)
    	return res
    } else if x <= min || x >= max {
    	for !(he.Val == max && he.Next.Val == min) {
    		he = he.Next
    	}
    	putAfter(he, tmp)
    	return res
    } else {
    	// fmt.Println("here")
    	for !(he.Val <= x && he.Next.Val > x) {
    		he = he.Next
    	}
    	putAfter(he, tmp)
    	return res
    }
    return res // never
}
// Go
// leetcode 558
// https://leetcode.cn/problems/logical-or-of-two-binary-grids-represented-as-quad-trees/

/**
 * Definition for a QuadTree node.
 * type Node struct {
 *     Val bool
 *     IsLeaf bool
 *     TopLeft *Node
 *     TopRight *Node
 *     BottomLeft *Node
 *     BottomRight *Node
 * }
 */

// a ? b : c
func ifOrNot(a bool, b, c *Node) *Node {
    if a {
        return b
    }
    return c
}

// 把 p 的四个子节点全设为 nil
func closeNode(p *Node) {
    p.TopLeft = nil
    p.TopRight = nil
    p.BottomLeft = nil
    p.BottomRight = nil
}

func intersect(p1 *Node, p2 *Node) *Node {
    res := &Node{}

    // 都是子节点
    if p1.IsLeaf && p2.IsLeaf {
        res.IsLeaf = true
        res.Val = p1.Val || p2.Val
        return res
    }

    // 找寻子节点
    res.TopLeft = intersect(ifOrNot(p1.IsLeaf, p1, p1.TopLeft), ifOrNot(p2.IsLeaf, p2, p2.TopLeft))
    res.TopRight = intersect(ifOrNot(p1.IsLeaf, p1, p1.TopRight), ifOrNot(p2.IsLeaf, p2, p2.TopRight))
    res.BottomLeft = intersect(ifOrNot(p1.IsLeaf, p1, p1.BottomLeft), ifOrNot(p2.IsLeaf, p2, p2.BottomLeft))
    res.BottomRight = intersect(ifOrNot(p1.IsLeaf, p1, p1.BottomRight), ifOrNot(p2.IsLeaf, p2, p2.BottomRight))

    // 根据子节点判断当前节点是否能变成一个 叶子节点
    a := res.TopLeft.IsLeaf && res.TopRight.IsLeaf && res.BottomLeft.IsLeaf && res.BottomRight.IsLeaf
    b := res.TopLeft.Val && res.TopRight.Val && res.BottomLeft.Val && res.BottomRight.Val
    c := res.TopLeft.Val || res.TopRight.Val || res.BottomLeft.Val || res.BottomRight.Val

    res.IsLeaf = a && (b || !c)
    res.Val = res.TopLeft.Val
    if res.IsLeaf {
        closeNode(res)
    }

    return res
}
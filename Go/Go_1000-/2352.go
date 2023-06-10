// Go
// leetcode 2352
// https://leetcode.cn/problems/equal-row-and-column-pairs/
type Node struct {
	cnt int
	next map[int]*Node
}

func (this *Node)search(x int) *Node {
	next, ok := this.next[x]
	if ok {
		return next
	}
	return nil
}

func (this *Node)checkIn(arr []int) {
	cur := this
	for _, x := range arr {
		next, ok := cur.next[x]
		if ok {
			cur = next
		} else {
			cur.next[x] = &Node{0, make(map[int]*Node)}
			cur = cur.next[x]
		}
	}
	cur.cnt++
}

func equalPairs(grid [][]int) int {
	res := 0
	root := &Node{0, make(map[int]*Node)}
	n := len(grid)
	for i:=0; i < n; i++ {
		root.checkIn(grid[i])
	}

	for j:=0; j<n; j++ {
		cur := root
		for i:=0; i<n && cur != nil; i++ {
			cur = cur.search(grid[i][j])
		}
		if cur != nil {
			res += cur.cnt
		}
	}
	return res
}
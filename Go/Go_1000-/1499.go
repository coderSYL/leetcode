// Go
// leetcode 1499
// https://leetcode.cn/problems/max-value-of-equation/

import (
	"container/heap"
)

type Item struct {
	x, y int
}
type PQ []*Item
func (pq PQ) Len() int { return len(pq) }
func (pq PQ) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].y - pq[i].x > pq[j].y - pq[j].x
}

func (pq PQ) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}
func (pq *PQ) Push(x any) {
	item := x.(*Item)
	*pq = append(*pq, item)
}
func (pq *PQ) Pop() any {
	old := *pq
	n := len(old)
	item := old[n-1]
	old[n-1] = nil  // avoid memory leak
	*pq = old[0 : n-1]
	return item
}

func (pq *PQ) PeekX() int {
	return (*pq)[0].x
}
func (pq *PQ) PopOne() *Item {
	item := heap.Pop(pq).(*Item)
	return item
}

func (pq *PQ) PeekYMinusX() int {
	return (*pq)[0].y - (*pq)[0].x
}

func findMaxValueOfEquation(points [][]int, k int) int {
	var h PQ
	n := len(points)
	res := -1000_000_000
	for i:=0; i<n; i++ {
		x, y := points[i][0], points[i][1]
		for h.Len() != 0 && x - h.PeekX() > k {
			h.PopOne()
		}
		if h.Len() != 0 {
			res = max(res, x + y + h.PeekYMinusX())
		}
		heap.Push(&h, &Item{x, y})
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
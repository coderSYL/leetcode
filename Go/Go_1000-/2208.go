// Go
// leetcode 2208
// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/

import (
	"container/heap"
)

type PQ []float64
func (pq PQ) Len() int { return len(pq) }
func (pq PQ) Less(i, j int) bool {
	return pq[i] > pq[j]
}
func (pq PQ) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PQ) Push(x any) {
	a := x.(float64)
	*pq = append(*pq, a)
}
func (pq *PQ) Pop() any {
	old := *pq
	n := len(old)
	a := old[n-1]
	*pq = old[0 : n-1]
	return a
}


func halveArray(nums []int) int {
	var h PQ
	
	var sum float64
	for _, x := range nums {
		a := float64(x)
		sum += a
		heap.Push(&h, a)
	}
	sum /= 2
	cnt := 0
	for sum > 0.00000001 {
		cnt++
		a := heap.Pop(&h).(float64)
		a /= 2
		sum -= a
		heap.Push(&h, a)
	}
	return cnt
}
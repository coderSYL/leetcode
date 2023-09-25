// Go
// leetcode 871
// https://leetcode.cn/problems/minimum-number-of-refueling-stops/

import (
	"container/heap"
)

type BigHeap []int

func (h BigHeap) Len() int { return len(h) }

// 名为 Less，实为 Greater
func (h BigHeap) Less(i, j int) bool { return h[i] > h[j] } // 大顶堆，返回值决定是否交换元素
func (h BigHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *BigHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *BigHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func minRefuelStops(target int, startFuel int, stations [][]int) int {
	h, n := &BigHeap{}, len(stations)
	heap.Init(h)
	for i := 0; i < n; i++ {
		x := stations[i][0]
		for startFuel < x {
			if h.Len() == 0 {
				return -1
			}
			startFuel += heap.Pop(h).(int)
		}
		heap.Push(h, stations[i][1])
	}
	// fmt.Println(h.Len(), heap.Pop(h).(int))

	for startFuel < target {
		if h.Len() == 0 {
			return -1
		}
		startFuel += heap.Pop(h).(int)
	}
	return n - h.Len()
}
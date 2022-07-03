// Go
// leetcode 871
// https://leetcode.cn/problems/minimum-number-of-refueling-stops/

import (
    "container/heap"
    "fmt"
)

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
// 名为 Less，实为 Greater
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }     // 小顶堆，返回值决定是否交换元素
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
    *h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}



func minRefuelStops(target int, startFuel int, stations [][]int) int {
	h, n := &IntHeap{}, len(stations)
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
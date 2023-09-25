// Go
// leetcode 630
// https://leetcode.cn/problems/course-schedule-iii/

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
func (h *BigHeap) Top() int {
	arr := *h
	return arr[0]
}


type SmallHeap []int

func (h SmallHeap) Len() int { return len(h) }

// 名为 Less，实为 Greater
func (h SmallHeap) Less(i, j int) bool { return h[i] < h[j] } // 小顶堆，返回值决定是否交换元素
func (h SmallHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *SmallHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}



func (h *SmallHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func scheduleCourse(courses [][]int) int {
	pq := &SmallHeap{}
	for _, course := range courses {
		heap.Push(pq, getId(course[0], course[1]))
	}
	chosen := &BigHeap{}
	time := 0
	
	for pq.Len() > 0 {
		duration, lastDay := getDurationAndLastDat(heap.Pop(pq).(int))

		if time + duration <= lastDay {
			heap.Push(chosen, duration)
			time += duration
		} else if chosen.Len() != 0 && chosen.Top() > duration {
			time += duration - heap.Pop(chosen).(int)
			heap.Push(chosen, duration)
		}
	}

	return chosen.Len()
}

func getId(duration, lastDay int) int { // 结束日占主导
	return lastDay * 20000 + duration
}

func getDurationAndLastDat(id int) (int, int) {
	return id%20000, id/20000
}
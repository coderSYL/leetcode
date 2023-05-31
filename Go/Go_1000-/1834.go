// Go
// leetcode 1834
// https://leetcode.cn/problems/single-threaded-cpu/

import (
	"container/heap"
)

func getOrder(tasks [][]int) []int {
	n := len(tasks)
	res := make([]int, 0, n)
	// sort.Slice(tasks, func(i, j int) bool {return tasks[i][0] <= tasks[j][0]})
	enqueueTimeQ := make([]int64, n)
	for i := 0; i < n; i++ {
		enqueueTimeQ[i] = int64(tasks[i][0])*int64(n) + int64(i)
	}
	sort.Slice(enqueueTimeQ, func(i, j int) bool { return enqueueTimeQ[i] <= enqueueTimeQ[j] })
	pForNotIn := 0
	curTime := int(enqueueTimeQ[0] / int64(n))
	var queue IntHeap
	//heap.Init(&queue)
	for len(res) < n {
		if len(queue) == 0 {
			nextTime := int(enqueueTimeQ[pForNotIn] / int64(n))
			if nextTime > curTime {
				curTime = nextTime
			}
		}
		// 确保满足时间要求的任务都在队列里
		for pForNotIn < n {
			enqueueTimeForThisTask := int(enqueueTimeQ[pForNotIn] / int64(n))
			if enqueueTimeForThisTask > curTime {
				break
			}
			taskId := int(enqueueTimeQ[pForNotIn] % int64(n))
			u := int64(tasks[taskId][1])*int64(n) + int64(taskId) // time * n + taskId
			queue.In(u)
			pForNotIn++
		}

		curU := queue.Out()
		taskId := int(curU % int64(n))
		timeUsed := int(curU / int64(n))
		res = append(res, taskId)
		curTime += timeUsed
	}
	return res
}

// 5 functions
type IntHeap []int64

func (h IntHeap) Len() int { return len(h) }

// 此为小根堆如需大根堆， h[i] > h[j]
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }

func (h IntHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

// Push 与 Pop需要改变size，所以用指针
func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int64))
}
func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// 可以再封一下
func (h *IntHeap) In(x int64) {
	heap.Push(h, x)
}

func (h *IntHeap) Out() int64 {
	return heap.Pop(h).(int64)
}
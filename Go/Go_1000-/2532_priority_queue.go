// Go
// leetcode 2532
// https://leetcode.cn/problems/time-to-cross-a-bridge/


import (
	"container/heap"
)

type Item struct {
	workerId    int // The value of the item; arbitrary.
	priority int    // The priority of the item in the queue.
	time int // The index of the item in the heap.
}
type PQ []*Item
func (pq PQ) Len() int { return len(pq) }
func (pq PQ) Less(i, j int) bool {
	// We want Pop to give us the highest, not lowest, priority so we use greater than here.
	return pq[i].priority > pq[j].priority
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

func (pq *PQ) Peek() *Item {
	return (*pq)[0]
}
func (pq *PQ) PopOne() *Item {
	item := heap.Pop(pq).(*Item)
	return item
}


func findCrossingTime(n int, k int, time [][]int) int {
	getWaitPriority := func(idx int) int {
		return 1001 * (time[idx][0] + time[idx][2]) + idx
	}

	var waitLeft, waitRight PQ // 优先级与工人效率相关
	var workLeft, workRight PQ // 优先级与完成时间相关

	for i:=0; i<k; i++ {
		heap.Push(&waitLeft, &Item{i, getWaitPriority(i), 0})
	}

	remain := n
	curTime := 0
	for remain > 0 || workRight.Len() > 0 || waitRight.Len() > 0 {
		for workLeft.Len() > 0 && workLeft.Peek().time <= curTime { // 左岸工人完成搬运
			item := heap.Pop(&workLeft).(*Item)
			item.priority = getWaitPriority(item.workerId)
			heap.Push(&waitLeft, item)
		}
		for workRight.Len() > 0 && workRight.Peek().time <= curTime { // 右岸工人完成搬运
			item := heap.Pop(&workRight).(*Item)
			item.priority = getWaitPriority(item.workerId)
			heap.Push(&waitRight, item)
		}
		
		if waitRight.Len() != 0 { // 右岸等待者过桥
			item := waitRight.PopOne()
			id := item.workerId
			curTime += time[id][2]
			item.time = curTime + time[id][3]
			item.priority = - item.time
			heap.Push(&workLeft, item)
			continue
		}

		if remain > 0 && waitLeft.Len() > 0 { // 左岸等待者过桥
            // fmt.Println(remain)
			remain--
			item := waitLeft.PopOne()
            id := item.workerId
			curTime += time[id][0]
			item.time = curTime + time[id][1]
			item.priority = - item.time
			heap.Push(&workRight, item)
			continue
		}

		// 不满足过桥条件时
		nextTime := 1<<31
		if workLeft.Len() > 0 {
			nextTime = min(nextTime, workLeft.Peek().time)
		}
		if workRight.Len() > 0 {
			nextTime = min(nextTime, workRight.Peek().time)
		}
		if nextTime != 1<<31 {
			curTime = nextTime
		}
	}
	return curTime
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
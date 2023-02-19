// Go
// leetcode 1792
// https://leetcode.cn/problems/maximum-average-pass-ratio/

import "container/heap"

func maxAverageRatio(classes [][]int, extraStudents int) float64 {
	n := len(classes)
	pq := &maxHeap{}
	heap.Init(pq)
	for i := 0; i < n; i++ {
		heap.Push(pq, classDate{i, getIncrese(classes[i][0], classes[i][1])})
	}

	for extraStudents > 0 {
		goodOne := heap.Pop(pq).(classDate)
		idx := goodOne.Index
		classes[idx][0]++
		classes[idx][1]++
		goodOne.increase = getIncrese(classes[idx][0], classes[idx][1])
		heap.Push(pq, goodOne)
		extraStudents--
	}

	var sum float64
	for i := 0; i < n; i++ {
		sum += float64(classes[i][0]) / float64(classes[i][1])
	}
	return sum / float64(n)
}

type classDate struct {
	Index    int
	increase float64
}

func getIncrese(pass, total int) float64 {
	return float64(total-pass) / float64(total*total+total)
}

type maxHeap []classDate

func (mh maxHeap) Len() int { return len(mh) }

func (mh maxHeap) Less(i, j int) bool { return mh[i].increase > mh[j].increase }

func (mh maxHeap) Swap(i, j int) { mh[i], mh[j] = mh[j], mh[i] }

func (mh *maxHeap) Push(x interface{}) {
	*mh = append(*mh, x.(classDate))
}

func (mh *maxHeap) Pop() interface{} {
	a := *mh
	v := a[len(a)-1]
	*mh = a[:len(a)-1]
	return v
}

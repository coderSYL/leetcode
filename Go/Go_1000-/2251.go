// Go
// leetcode 2251
// https://leetcode.cn/problems/number-of-flowers-in-full-bloom/

// SmallHeap
import "container/heap"
type SmallHeap []int
func (h SmallHeap) Len() int { return len(h) }
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
func (h *SmallHeap) Top() int {
	arr := *h
	return arr[0]
}

func fullBloomFlowers(flowers [][]int, people []int) []int {
	sort.Slice(flowers, func(i, j int) bool { // 先开的花在前面，同时开的花，先谢的在前面
		a, b := flowers[i], flowers[j]
		if a[0] != b[0] {
			return a[0] < b[0]
		}
		return a[1] < b[1]
	})
	now := &SmallHeap{}
	n := len(people)
	order := make([]int, n)
	for i, _ := range order {
		order[i] = i
	}

	sort.Slice(order, func(i, j int) bool {
		a, b := order[i], order[j]
		return people[a] < people[b]
	})
	start:= 0
	m := len(flowers)
	res := make([]int, n)
	for _, idx := range order {
		time := people[idx]
		for start < m && flowers[start][0] <= time { // start 前面的花都开过
			heap.Push(now, flowers[start][1])
			start++
		}

		for now.Len() > 0 && now.Top() < time {
			heap.Pop(now)
		}

		res[idx] = now.Len()
	}

	return res
}
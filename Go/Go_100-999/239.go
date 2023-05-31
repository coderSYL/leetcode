// Go
// leetcode 239
// https://leetcode.cn/problems/sliding-window-maximum/

func maxSlidingWindow(nums []int, k int) []int {
	if k == 1 {
		return nums
	}
	pq := &IntHeap{}
	heap.Init(pq)
	for i := 0; i < k-1; i++ {
		heap.Push(pq, getNum(i, nums[i]))
	}

	res := make([]int, len(nums)-k+1)
	for i := 0; i < len(res); i++ {
		u := i + k - 1
		heap.Push(pq, getNum(u, nums[u]))
		for (*pq).Len() != 0 && pq.GetIdx() < i {
			heap.Pop(pq)
		}
		res[i] = pq.GetVal()
	}
	return res
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i]%20020 > h[j]%20020 }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}
func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *IntHeap) GetIdx() int {
	x := (*h)[0]
	return x / 20020
}
func (h *IntHeap) GetVal() int {
	x := (*h)[0]
	return x%20020 - 10010
}

func getNum(i, x int) int {
	return i*20020 + x + 10010
}
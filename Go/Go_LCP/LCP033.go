// Go
// leetcode LCP 33
// https://leetcode.cn/problems/o8SXZn/

func storeWater(bucket []int, vat []int) (res int) {
	n := len(bucket)
	h := &IntHeap{}
	heap.Init(h)
	for i := 0; i < n; i++ {
		heap.Push(h, getNum(bucket[i], vat[i]))
	}
	res = getTimes(h.GetTop())

	cnt := 0
	for {
		cnt++
		x := heap.Pop(h).(int)
		once, need := getOnceAndNeed(x)
		once++
		heap.Push(h, getNum(once, need))
		cur := getTimes(h.GetTop())
		if cur+cnt > res+2*n {
			break
		}
		res = min(res, cur+cnt)
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func getNum(once, need int) int {
	return once*100000 + need
}

func getOnceAndNeed(x int) (int, int) {
	return x / 100000, x % 100000
}

func getTimes(x int) int {
	once, need := x/100000, x%100000
	if need == 0 {
		return 0
	}
	if once == 0 {
		return 10000
	}
	res := need / once
	if need%once != 0 {
		res++
	}
	return res
}

func getSpecificTimes(x int) float64 {
	if x == 0 {
		return 0
	}
	if x < 100000 {
		return 10000.0
	}
	once, need := float64(x/100000), float64(x%100000)
	return need / once
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return getSpecificTimes(h[i]) > getSpecificTimes(h[j]) }
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

func (h *IntHeap) GetTop() int {
	return (*h)[0]
}
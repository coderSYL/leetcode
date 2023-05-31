// Go
// leetcode 1439
// https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

func kthSmallest(mat [][]int, k int) int {
	m, n := len(mat), len(mat[0])
	a := []int{0}
	for i := 0; i < m; i++ {
		h := &IntHeap{}
		for _, x := range a {
			for j := 0; j < n; j++ {
				u := x + mat[i][j]
				if h.Len() < k {
					heap.Push(h, u)
				} else {
					heap.Push(h, u)
					heap.Pop(h)
				}
			}
		}
		a = *h
		// fmt.Println(a)
	}
	return a[0]
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *IntHeap) Top() int {
	old := *h
	n := len(old)
	x := old[n-1]
	return x
}
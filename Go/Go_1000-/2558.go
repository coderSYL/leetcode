// Go
// leetcode 2558
// https://leetcode.cn/problems/take-gifts-from-the-richest-pile/

// BigHeap
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

func pickGifts(gifts []int, k int) (res int64) {
	var h BigHeap
	for _, x := range gifts {
		heap.Push(&h, x)
		res += int64(x)
	}
	for k > 0 {
		k--
		x := heap.Pop(&h).(int)
		nx := getSqrt(x)
		res -= int64(x-nx)
		heap.Push(&h, nx)
	}
	return res
}

func getSqrt(x int) int {
	l, r := 1, x
	for l <= r {
		mid := (l+r)/2
		if mid*mid > x {
			r = mid-1
		} else {
			l = mid + 1
		}
	}
	return l-1
}
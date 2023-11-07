// Go
// leetcode 2530
// https://leetcode.cn/problems/maximal-score-after-applying-k-operations/
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

func maxKelements(nums []int, k int) (res int64) {
    h := &BigHeap{}
    for _,x := range nums {
        heap.Push(h, x)
    }
    for k > 0 {
        k--
        x := heap.Pop(h).(int)
        res += int64(x)
        heap.Push(h, oneThreeCeil(x))
    }
    return res
}

func oneThreeCeil(x int) int {
    if x % 3 == 0 {
        return x/3
    }
    return x/3 + 1
}
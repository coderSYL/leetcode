package main

import (
	"container/heap"
	"fmt"
)

func main() {
	h := &IntHeap{5, 1, 3, 10, -3}
	heap.Init(h)
	for h.Len() > 0 {
		fmt.Println(heap.Pop(h).(int))
	}
}

func repair(timeInMin int64, cap int, rVal int64) int64 {
	// 给一个能力为 cap 的技师 timeInMin分钟
	// 能修好多少辆车
	cap64 := int64(cap)
	l, r := int64(0), int64(rVal)
	if r <= 0 {
		r = 1000_000_000
	}
	upperBoundary := timeInMin / cap64

	for l <= r {
		mid := (l + r) / 2
		if mid*mid <= upperBoundary { // 修得完
			l = mid + 1
		} else { // 修不完
			r = mid - 1
		}
	}
	return r
}

func generateCode(arr []int) int64 {
	var res int64
	for i, x := range arr {
		u := int64(x) << (2 * i)
		res += u
	}
	return res
}

func decode(x int64) []int {
	res := make([]int, 25)
	for i := 0; i < 25; i++ {
		val := int((x >> (2 * i)) & 11)
		res[i] = val
	}
	return res
}

func printInLine(arr []int, lineSize int) {
	n := len(arr)
	turn := (n / lineSize) + 1
	fmt.Println(n, lineSize)
	for i := 0; i < turn; i++ {
		end := (i + 1) * lineSize
		if n < end {
			end = n
		}
		fmt.Println(arr[i*lineSize : end])
	}
}

func lowbit(x int) int {
	return x & -x
}

func power(a, b int) int {
	res := 1
	for b > 0 {
		res *= a
		b--
	}
	return res
}

type IntHeap []int

func (h IntHeap) Len() int { return len(h) }

// 名为 Less，实为 Greater
func (h IntHeap) Less(i, j int) bool { return h[i] > h[j] } // 小顶堆，返回值决定是否交换元素
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

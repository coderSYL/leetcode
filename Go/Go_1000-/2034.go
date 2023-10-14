// Go
// leetcode 2034
// https://leetcode.cn/problems/stock-price-fluctuation/
import (
	"container/heap"
)

type StockPrice struct {
	currentTime int
	price map[int]int
	maxPrice, minPrice BigHeap
}


func Constructor() StockPrice {
	return StockPrice{price : map[int]int{}}
}


func (this *StockPrice) Update(timestamp int, price int)  {
	this.currentTime = max(this.currentTime, timestamp)
	this.price[timestamp] = price
	x := getID(timestamp, price)
	heap.Push(&this.maxPrice, x)
	heap.Push(&this.minPrice, -x)
}


func (this *StockPrice) Current() int {
	return this.price[this.currentTime]
}


func (this *StockPrice) Maximum() int {
	for {
		x := this.maxPrice.Top()
		time, price := getTimeAndPrice(x)
		if this.price[time] == price {
			return price
		}
		heap.Pop(&this.maxPrice)
	}
	return -1 // void
}


func (this *StockPrice) Minimum() int {
	for {
		x := -this.minPrice.Top()
		time, price := getTimeAndPrice(x)
		if this.price[time] == price {
			return price
		}
		heap.Pop(&this.minPrice)
	}
	return -1
}


/**
 * Your StockPrice object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Update(timestamp,price);
 * param_2 := obj.Current();
 * param_3 := obj.Maximum();
 * param_4 := obj.Minimum();
 */


// BigHeap


type BigHeap []int64
func (h BigHeap) Len() int { return len(h) }
// 名为 Less，实为 Greater
func (h BigHeap) Less(i, j int) bool { return h[i] > h[j] } // 大顶堆，返回值决定是否交换元素
func (h BigHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *BigHeap) Push(x interface{}) {
	*h = append(*h, x.(int64))
}
func (h *BigHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
func (h *BigHeap) Top() int64 {
	arr := *h
	return arr[0]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func getID(time, price int) int64 {
	return int64(price) * 1000_000_001 + int64(time)
}

func getTimeAndPrice(x int64) (int, int) {
	price := int(x/1000_000_001)
	time := int(x%1000_000_001)
	return time, price
}
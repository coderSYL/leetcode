// Go
// leetcode 901
// https://leetcode.cn/problems/online-stock-span/

type StockSpanner struct {
	cnt int
	arr []int
}


func Constructor() StockSpanner {
	return StockSpanner{}
}


func (this *StockSpanner) Next(price int) int {
	id := this.cnt
	this.cnt++
	u := price * 10010 + id
	a := this.arr
	n := len(a)-1
	for n >= 0 && a[n] < u {
		n--
	}
	pre := -1
	if n >= 0 {
		pre = a[n] % 10010
	}
	

	res := id-pre
	this.arr = this.arr[:n+1]
	this.arr = append(this.arr, u)
	return res
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
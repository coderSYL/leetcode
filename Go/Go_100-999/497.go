// Go
// leetcode 497
// https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/

type Solution struct {
	rs [][]int
	pre_sum []int
	n int
}


func Constructor(rects [][]int) Solution {
	sum, n := make([]int, len(rects) + 1), len(rects)
    sum[0] = 0
	for i := 0; i < n; i++ {
		sum[i + 1] = sum[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1)
	}
	return Solution{rects, sum, n}
}


func (this *Solution) Pick() []int {
	val := rand.Intn(this.pre_sum[this.n]) + 1
	l, r, mid := 0, this.n, 0
	for l < r {
		mid = (l + r) >> 1
		if(this.pre_sum[mid] >= val) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	cur := this.rs[r-1][0:4]
	
	x := rand.Intn(cur[2] - cur[0] + 1) + cur[0]
	y := rand.Intn(cur[3] - cur[1] + 1) + cur[1]
	return []int{x, y}
}


/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(rects);
 * param_1 := obj.Pick();
 */
// Go
// leetcode 57
// https://leetcode.cn/problems/insert-interval/

func insert(intervals [][]int, newInterval []int) [][]int {
	n := len(intervals)
	a, b := newInterval[0], newInterval[1]
	l, r := 0, n-1
	diff := 1
	for l <= r && diff > 0{
		mid := (l + r) / 2
		diff = 0
		if intervals[mid][0] > b {
			diff += r - mid + 1
			r = mid - 1
		}
		if intervals[mid][1] < a {
			diff += mid + 1 - l
			l = mid + 1
		}
	}
	size := r - l + 1
	res := make([][]int, n+1-size)
	for i := 
}
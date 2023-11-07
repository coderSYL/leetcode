// Go
// leetcode 275
// https://leetcode.cn/problems/h-index-ii/

func hIndex(citations []int) int {
	n := len(citations)
	l, r := 0, n-1
	for l<=r {
		mid := (l+r)/ 2
		if citations[mid] >= n-mid { // ok
			r = mid-1
		} else {
			l = mid+1
		}
	}
	return n-l
}
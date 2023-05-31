// Go
// leetcode 1637
// https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points/

func maxWidthOfVerticalArea(points [][]int) (res int) {
	n := len(points)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = points[i][0]
	}
	sort.Ints(arr)
	for i := 1; i < n; i++ {
		res = max(res, arr[i]-arr[i-1])
	}
	return res
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}
// Go
// leetcode 768
// https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/

func maxChunksToSorted(arr []int) int {
	n := len(arr)
	mx, mn := make([]int, n), make([]int, n)
	mx[0], mn[n-1] = arr[0], arr[n-1]
	for i := 1; i < n; i++ {
		mx[i] = max(mx[i-1], arr[i])
		mn[n-1-i] = min(mn[n-i], arr[n-i-1])
	}

	res := 1
	for i := 1; i < n; i++ {
		if mn[i] >= mx[i-1] {
			res++
		}
	}
	return res
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
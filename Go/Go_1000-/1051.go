// Go
// leetcode 1051
// https://leetcode.cn/problems/height-checker/

func heightChecker(heights []int) int {
	n := len(heights)
	arr := make([]int, n)
	copy(arr, heights)
	sort.Ints(arr)
	res := 0
	for i := 0; i < n; i++ {
		if arr[i] != heights[i] {
			res++
		}
	}
	return res
}
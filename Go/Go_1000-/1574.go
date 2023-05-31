// Go
// leetcode 1574
// https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

import "sort"

func findLengthOfShortestSubarray(arr []int) int {
	n := len(arr)
	l := 1
	for l < n && arr[l-1] <= arr[l] {
		l++
	}
	if l == n {
		return 0
	}

	r := n - 2
	for r >= 0 && arr[r] <= arr[r+1] {
		r--
	}
	r++

	res := r
	for i := 0; i < l; i++ {
		goodRForI := sort.SearchInts(arr[r:], arr[i])
		// fmt.Println(i, goodRForI+r)
		res = min(res, goodRForI+r-i-1)
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
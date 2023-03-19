import "sort"

// Go
// leetcode 2389
// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/

func answerQueries(nums []int, queries []int) []int {
	sort.Ints(nums)
	m, n := len(queries), len(nums)
	res := make([]int, m)
	for i := 1; i < n; i++ {
		nums[i] += nums[i-1]
	}
	for i := 0; i < m; i++ {
		res[i] = getMaxLen(nums, queries[i])
	}
	return res
}

func getMaxLen(nums []int, limit int) int {
	l, r := 0, len(nums)-1
	for l <= r {
		mid := (l + r) >> 1
		if nums[mid] < limit {
			l = mid + 1
		} else if nums[mid] > limit {
			r = mid - 1
		} else {
			return mid + 1
		}
	}
	// r+1 or l
	return l
}
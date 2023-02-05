import "sort"

// Go
// leetcode 2389
// https://leetcode.cn/problems/longest-subsequence-with-limited-sum/

func answerQueries(nums []int, queries []int) []int {
	// 先排序，再求前缀和
	sort.Ints(nums)
	m, n := len(nums), len(queries)
	for i := 1; i < m; i++ {
		nums[i] += nums[i-1]
	}

	res := make([]int, n)
	for i, x := range queries {
		l, r := 0, m-1
		for l <= r {
			mid := (l + r) >> 1
			if nums[mid] <= x {
				l = mid + 1
			} else {
				r = mid - 1
			}
		}
		res[i] = l
	}
	return res
}
import "sort"

// Go
// leetcode 1798
// https://leetcode.cn/problems/maximum-number-of-consecutive-values-you-can-make/

func getMaximumConsecutive(coins []int) int {
	sort.Ints(coins)
	res := 1
	for _, x := range coins {
		if x > res {
			return res
		}
		res += x
	}
	return res
}
// Go
// leetcode 1403
// https://leetcode.cn/problems/minimum-subsequence-in-non-increasing-order/

func minSubsequence(nums []int) []int {
	n := len(nums)
	tmp := make([]int, n)
	copy(tmp, nums)
	sort.Slice(tmp, func(i, j int) bool {
		return tmp[i] > tmp[j]
	})
	sum := 0
	for _, v := range nums {
		sum += v
	}
	cur, i := 0, 0
	for cur * 2 <= sum {
		cur += tmp[i]
		i++
	}

	return tmp[0 : i]
}
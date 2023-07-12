// Go
// leetcode 1911
// https://leetcode.cn/problems/maximum-alternating-subsequence-sum/

func maxAlternatingSum(nums []int) int64 {
	n :=len(nums)
	add, minus := int64(nums[0]), int64(0)
	for i:=1; i < n; i++ {
		x := int64(nums[i])
		add, minus = max(add, minus + x), max(minus, add-x)
	}
	return max(add, minus)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
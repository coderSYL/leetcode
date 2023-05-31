// Go
// leetcode 1031
// https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/

func maxSumTwoNoOverlap(nums []int, firstLen int, secondLen int) (res int) {
	n := len(nums)
	sum := make([]int, n+1)
	for i, x := range nums {
		sum[i+1] = sum[i] + x
	}

	maxSumA, maxSumB := 0, 0
	for i := firstLen + secondLen; i <= n; i++ {
		maxSumA = max(maxSumA, sum[i-secondLen]-sum[i-secondLen-firstLen])
		maxSumB = max(maxSumB, sum[i-firstLen]-sum[i-secondLen-firstLen])
		res = max(res, max(maxSumA+sum[i]-sum[i-secondLen], maxSumB+sum[i]-sum[i-firstLen]))
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
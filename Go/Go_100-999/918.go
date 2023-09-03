// Go
// leetcode 918
// https://leetcode.cn/problems/maximum-sum-circular-subarray/

func maxSubarraySumCircular(nums []int) int {
	n := len(nums)
	pre := make([]int, n+1)
	mn, mx := 0, -1000_000_000
	cur := 1000_000_000
	res := nums[0]
	for i := range nums {
		pre[i+1] = pre[i] + nums[i]
		cur = min(cur, pre[i+1] - mx)
		res = max(res, pre[i+1] - mn)
		mn = min(mn, pre[i+1])
		mx = max(mx, pre[i+1])
	}

	return max(pre[n] - cur, res)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
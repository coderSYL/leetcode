// Go
// leetcode 1749
// https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray/

func maxAbsoluteSum(nums []int) int {
	res := 0
	cur := 0
	mn, mx := 0, 0
	for _,x :=range nums {
		cur += x
		// fmt.Println(cur, mx, mn)
		res = max(res, abs(cur - mn))
		res = max(res, abs(cur - mx))
		mx = max(mx, cur)
		mn = min(mn, cur)
	}
	return res
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

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
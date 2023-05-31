// Go
// leetcode 2104
// https://leetcode.cn/problems/sum-of-subarray-ranges/

func subArrayRanges(nums []int) (res int64) {
	ma, mi, n := 0, 0, len(nums)
	for i, x := range nums {
		ma, mi = x, x
		for j := i + 1; j < n; j++ { // 暴力
			ma = max(ma, nums[j])
			mi = min(mi, nums[j])
			res += int64(ma - mi)
		}
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
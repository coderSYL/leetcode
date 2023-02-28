// Go
// leetcode 1144
// https://leetcode.cn/problems/decrease-elements-to-make-array-zigzag/

func movesToMakeZigzag(nums []int) int {
	n := len(nums)
	cnt := make([]int, 2)

	for i, val := range nums {
		u := i & 1
		x := val
		if i > 0 {
			x = min(x, nums[i-1]-1)
		}
		if i < n-1 {
			x = min(x, nums[i+1]-1)
		}
		cnt[u] += val - x
	}
	return min(cnt[0], cnt[1])
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
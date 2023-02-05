// Go
// leetcode 628
// https://leetcode.cn/problems/maximum-product-of-three-numbers/

func maximumProduct(nums []int) int {
	n := len(nums)
	f := [2][4]int{}
	f[0][0] = 1
	f[1][0] = 1
	if nums[0] < nums[1] {
		f[0][1], f[1][1] = nums[0], nums[1]
	} else {
		f[0][1], f[1][1] = nums[1], nums[0]
	}
	f[0][2] = nums[0] * nums[1]
	f[1][2] = nums[0] * nums[1]
	f[0][3] = 1_000_000_000
	f[1][3] = -1_000_000_000

	for i := 2; i < n; i++ {
		t := nums[i]
		for j := 2; j >= 0; j-- {
			x, y := f[0][j]*t, f[1][j]*t
			f[0][j+1] = min(x, y, f[0][j+1])
			f[1][j+1] = max(x, y, f[1][j+1])
		}
	}
	return f[1][3]
}

func min(a, b, c int) int {
	if b < a {
		a = b
	}
	if c < a {
		return c
	}
	return a
}

func max(a, b, c int) int {
	if a < b {
		a = b
	}
	if c > a {
		return c
	}
	return a
}
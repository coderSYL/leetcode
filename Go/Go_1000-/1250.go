// Go
// leetcode 1250
// https://leetcode.cn/problems/check-if-it-is-a-good-array/

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func isGoodArray(nums []int) bool {
	n := len(nums)
	cur := nums[0]
	for i := 1; i < n; i++ {
		cur = gcd(cur, nums[i])
		if cur == 1 {
			break
		}
	}
	return cur == 1
}
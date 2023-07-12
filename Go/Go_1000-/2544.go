// Go
// leetcode 2544
// https://leetcode.cn/problems/alternating-digit-sum/

func alternateDigitSum(n int) (ans int) {
	sign := 1
	for n > 0 {
		ans += sign * n % 10
		sign *= -1
		n /= 10

	}
	if sign == 1 {
		ans *= -1
	}

	return ans
}
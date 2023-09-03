// Go
// leetcode 1281
// https://leetcode.cn/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

func subtractProductAndSum(n int) int {
	sum, product := 0, 1
	for n > 0 {
		u := n % 10
		n /= 10

		sum += u
		product *= u
	}

	return product - sum
}
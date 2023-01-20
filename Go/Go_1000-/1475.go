// Go
// leetcode 1475
// https://leetcode.cn/problems/final-prices-with-a-special-discount-in-a-shop/

func finalPrices(prices []int) []int {
	n := len(prices)
	res := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		x, j := prices[i], i + 1
		for  ; j < n; j++ {
			if prices[j] <= x {
				break
			}
		}
		if j == n {
			res[i] = x
		} else {
			res[i] = x - prices[j]
		}
	}
	return res
}
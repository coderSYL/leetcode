// Go
// leetcode 121
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

func maxProfit(prices []int) int {
	mn := 10000
	res := 0
	for _, x := range prices {
		res = max(res, x - mn)
		mn = min(mn, x)
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
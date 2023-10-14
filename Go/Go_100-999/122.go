// Go
// leetcode 122
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

func maxProfit(prices []int) int {
	res := 0
	takeMax := -1000000
	for _, x := range prices {
		next := max(res, takeMax + x)
		takeMax = max(takeMax, res - x)
		res = next
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
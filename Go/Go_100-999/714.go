// Go
// leetcode 714
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

func maxProfit(prices []int, fee int) int {
	cnt := []int{-100000000, 0}
	for _, x := range prices {
		cnt[0] = max(cnt[0], cnt[1]-x)
		cnt[1] = max(cnt[1], cnt[0] + x - fee)
	}
	return cnt[1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
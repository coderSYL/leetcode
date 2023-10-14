// Go
// leetcode 309
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

func maxProfit(prices []int) int {
	cnt := []int{-10000000, 0, 0} // 持有，可买，冻结
	for _, x := range prices {
		cnt[0] = max(cnt[0], cnt[1]-x)
		cnt[1] = max(cnt[1], cnt[2])
		cnt[2] = cnt[0] + x
	}
	return max(cnt[1], cnt[2])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
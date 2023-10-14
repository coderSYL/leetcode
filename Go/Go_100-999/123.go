// Go
// leetcode 123
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/

func maxProfit(prices []int) int {
	memo := make([][]int, 2)
	for i := 0; i < 2; i++ {
		memo[i] = []int{-1000_000, 0} // 买后，卖后
	}
	for _, x := range prices {
		memo[1][1] = max(memo[1][1], memo[1][0]+x)
		memo[1][0] = max(memo[1][0], memo[0][1]-x)
		memo[0][1] = max(memo[0][1], memo[0][0]+x)
		memo[0][0] = max(memo[0][0], -x)
	}

	res := max(memo[1][1], memo[0][1])
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
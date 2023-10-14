// Go
// leetcode 188
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

func maxProfit(k int, prices []int) int {
	memo := make([][]int, k)
	for i:=0; i<k; i++ {
		memo[i] = []int{-100000,0}
	}
	for _, x := range prices {
		for i:=k-1; i> 0; i-- {
			memo[i][1] = max(memo[i][1], memo[i][0] + x)
			memo[i][0] = max(memo[i][0], memo[i-1][1] - x)
		}
		memo[0][1] = max(memo[0][1], memo[0][0] + x)
		memo[0][0] = max(memo[0][0], -x)
	}

	res := 0
	for i:=0; i<k; i++ {
		res = max(res, memo[i][1])
	}

	return res
}


func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
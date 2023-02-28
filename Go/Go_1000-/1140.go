// Go
// leetcode 1140
// https://leetcode.cn/problems/stone-game-ii/

func stoneGameII(piles []int) int {
	n := len(piles)
	sum := make([]int, n+1)
	for i := 0; i < n; i++ {
		sum[i+1] = sum[i] + piles[i]
	}

	dp := make([][]int, n+1)
	m := n/3 + 10
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m)
	}

	for i := 0; i < m; i++ {
		dp[n-1][i] = piles[n-1]
	}

	for i := n - 1; i >= 0; i-- { // dp[i][all]
		restSum := sum[n] - sum[i]
		for j := 1; j < m; j++ { // dp[i][j]
			if i+2*j >= n {
				dp[i][j] = restSum
				continue
			}
			minDp := restSum
			for x := 1; x <= 2*j; x++ {
				if i+x > n || x >= m {
					break
				}
				minDp = min(minDp, dp[i+x][max(j, x)])
			}
			dp[i][j] = restSum - minDp
		}
	}
	return dp[0][1]
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
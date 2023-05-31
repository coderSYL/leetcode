// Go
// leetcode 1092
// https://leetcode.cn/problems/shortest-common-supersequence/

func shortestCommonSupersequence(s string, t string) string {
	n, m := len(s), len(t)
	dp := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = make([]int, m+1)
	}

	var calculate func(int, int) int
	calculate = func(i int, j int) int {
		if dp[i][j] != 0 {
			return dp[i][j]
		}
		if i*j == 0 {
			dp[i][j] = i + j
			return dp[i][j]
		}

		if s[i-1] == t[j-1] {
			dp[i][j] = calculate(i-1, j-1) + 1
			return dp[i][j]
		}

		dp[i][j] = min(calculate(i-1, j), calculate(i, j-1)) + 1
		return dp[i][j]
	}

	bs := make([]byte, calculate(n, m))
	x, y := n-1, m-1
	for i := len(bs) - 1; i >= 0; i-- {
		if x == -1 {
			for y >= 0 {
				bs[i] = t[y]
				i--
				y--
			}
			continue
		}
		if y == -1 {
			for x >= 0 {
				bs[i] = s[x]
				i--
				x--
			}
			continue
		}
		if s[x] == t[y] {
			bs[i] = s[x]
			x--
			y--
		} else if dp[x+1][y+1] == dp[x][y+1]+1 {
			bs[i] = s[x]
			x--
		} else {
			bs[i] = t[y]
			y--
		}
	}
	return string(bs)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
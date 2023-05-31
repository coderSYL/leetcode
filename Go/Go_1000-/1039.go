// Go
// leetcode 1039
// https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/

func minScoreTriangulation(values []int) int {
	n := len(values)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)

	}

	var dfs func(int, int) int
	dfs = func(i, j int) int {
		pointNum := j - i + 1
		if pointNum == 2 {
			return 0
		}
		if dp[i][j] > 0 {
			return dp[i][j]
		}
		cur := values[i] * values[j]
		resForDfs := 1 << 30
		for k := i + 1; k < j; k++ {
			resForDfs = min(resForDfs, dfs(i, k)+dfs(k, j)+cur*values[k])
		}
		dp[i][j] = resForDfs
		return resForDfs
	}
	return dfs(0, n-1)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
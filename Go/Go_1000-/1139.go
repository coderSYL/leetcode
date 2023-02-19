// Go
// leetcode 1139
// https://leetcode.cn/problems/largest-1-bordered-square/

func largest1BorderedSquare(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	largestLength := 0
	rowSum := make([][]int, m)
	for i := 0; i < m; i++ {
		rowSum[i] = make([]int, n+1)
	}

	colSum := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		colSum[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			rowSum[i][j+1] = rowSum[i][j] + grid[i][j]
			colSum[i+1][j] = colSum[i][j] + grid[i][j]
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			for length := min(m-i, n-j); length > largestLength; length-- { // 检查四条边
				if rowSum[i][j+length]-rowSum[i][j] == length && // 上边
					rowSum[i+length-1][j+length]-rowSum[i+length-1][j] == length && // 下边
					colSum[i+length][j]-colSum[i][j] == length && // 左边
					colSum[i+length][j+length-1]-colSum[i][j+length-1] == length { // 右边
					largestLength = length
				}
			}
		}
	}
	return largestLength * largestLength
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// Go
// leetcode offer47
// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/

func maxValue(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	for i := 1; i < m; i++ { // 处理第一列数据
		grid[i][0] += grid[i-1][0]
	}
	for i := 1; i < n; i++ { // 处理第一行数据
		grid[0][i] += grid[0][i-1]
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			grid[i][j] += max(grid[i][j-1], grid[i-1][j])
		}
	}
	return grid[m-1][n-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
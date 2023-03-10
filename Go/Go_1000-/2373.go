// Go
// leetcode 2373
// https://leetcode.cn/problems/largest-local-values-in-a-matrix/

func largestLocal(grid [][]int) [][]int {
	n := len(grid)
	res := make([][]int, n-2)
	for i := 0; i < n-2; i++ {
		res[i] = make([]int, n-2)
	}

	for i := 0; i < n; i++ {
		for x := i - 2; x <= i; x++ {
			if x < 0 || x >= n-2 {
				continue
			}
			for j := 0; j < n; j++ {
				for y := j - 2; y <= j; y++ {
					if y < 0 || y >= n-2 {
						continue
					}
					res[x][y] = max(res[x][y], grid[i][j])
				}
			}
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
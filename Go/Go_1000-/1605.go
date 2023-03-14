// Go
// leetcode 1605
// https://leetcode.cn/problems/find-valid-matrix-given-row-and-column-sums/

func restoreMatrix(rowSum []int, colSum []int) [][]int {
	m, n := len(rowSum), len(colSum)
	res := make([][]int, m)
	for i := 0; i < m; i++ {
		res[i] = make([]int, n)
		for j := 0; j < n; j++ {
			x := min(rowSum[i], colSum[j])
			rowSum[i] -= x
			colSum[j] -= x
			res[i][j] = x
		}
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
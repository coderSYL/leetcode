// Go
// leetcode 1252
// https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/

func oddCells(m int, n int, indices [][]int) (res int) {
	row, col := make([]int, m), make([]int, n)
	for _, p := range indices {
		row[p[0]]++
		col[p[1]]++
	}
	for _, x := range row {
		for _, y := range col {
			res += (x + y) & 1
		}
	}
	return res
}
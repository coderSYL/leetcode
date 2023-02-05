// Go
// leetcode 498
// https://leetcode.cn/problems/diagonal-traverse/

func findDiagonalOrder(mat [][]int) []int {
	m, n, idx, cur := len(mat), len(mat[0]), 0, 0
	bound := m + n - 2
	d := [2]int{-1, 1}
	res := make([]int, m*n)
	for cur <= bound {
		p := cur & 1
		x, y := cur*(1-p), cur*p
		if x >= m {
			y = x - m + 1
			x = m - 1
		}
		if y >= n {
			x = y - n + 1
			y = n - 1
		}
		for x >= 0 && x < m && y >= 0 && y < n {
			res[idx] = mat[x][y]
			idx++
			x += d[p]
			y += d[1-p]
		}
		cur++
	}
	return res
}
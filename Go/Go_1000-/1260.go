// Go
// leetcode 1260
// https://leetcode.cn/problems/shift-2d-grid/

func shiftGrid(g [][]int, k int) [][]int {
	m, n := len(g), len(g[0])
	mn := m * n
	k %= mn

	if k == 0 {
		return g
	}

	arr := make([]int, k)

	p, x, y := 0, 0, 0

	for p < k {
		arr[p] = g[x][y]
		p++
		y++
		if y == n {
			y = 0
			x++
		}
	}

	p = 0
	for mn > 0 {
		mn--

		g[x][y], arr[p] = arr[p], g[x][y]
		p = (p + 1) % k
		y++
		if y == n {
			x++
			y = 0
		}

		x %= m
	}

	return g
}
// Go
// leetcode 688
// https://leetcode.cn/problems/knight-probability-in-chessboard/

func knightProbability(n int, k int, row int, column int) float64 {
	g := make([][][]float64, 2)
	dirs := [8][2]int{{2, 1}, {2, -1}, { -2, 1}, { -2, -1}, {1, 2}, {1, -2}, { -1, 2}, { -1, -2}}
	g[0] = getSquarefloat64(n)
	g[1] = getSquarefloat64(n)
	g[0][row][column] = 1.00000000000
	for step := 1; step <= k; step++ {
		cur:=step%2
		pre := 1-cur
		setZero(g[cur])
		for i:=0; i<n; i++ {
			for j:=0; j<n; j++ {
				val := g[pre][i][j] / 8.000000000000000000
				if val == 0 {
					continue
				}
				for _, dir := range dirs {
					nx, ny := i+dir[0], j+dir[1]
					if nx < 0 || ny<0 || nx >= n || ny >= n {
						continue
					}
					g[cur][nx][ny] += val
				}
			}
		}
	}

	var inBoard float64
	for i:=0; i<n; i++ {
		for j:= 0; j<n; j++ {
			inBoard += g[k%2][i][j]
		}
	}
	return inBoard
}

func getSquarefloat64(n int) [][]float64 {
	res := make([][]float64, n)
	for i:=0; i<n; i++ {
		res[i] = make([]float64, n)
	}
	return res
}

func setZero(g [][]float64) {
	m, n := len(g), len(g[0])
	for i:=0; i<m; i++ {
		for j:=0; j<n; j++ {
			g[i][j] = 0
		}
	}
}
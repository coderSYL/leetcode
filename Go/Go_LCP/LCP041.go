// Go
// leetcode LCP 41
// https://leetcode.cn/problems/fHi6rV/

func flipChess(chessboard []string) int {
	n, m := len(chessboard), len(chessboard[0])
	g := make([][]byte, n)
	for i := 0; i < n; i++ {
		g[i] = []byte(chessboard[i])
	}
	gInit := func() {
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				g[i][j] = chessboard[i][j]
			}
		}
	}

	black, white, blank := byte('X'), byte('O'), byte('.')
	// fmt.Println(g)

	dirs := [][2]int{{-1, -1}, {-1, 0}, {0, -1}, {1, -1},
		{-1, 1}, {1, 1}, {0, 1}, {1, 0}}

	var dfs func(int, int) int
	dfs = func(x, y int) int {
		res := 0

		// fmt.Println(dfsCnt)

		for _, p := range dirs { // one direction per loop
			ok := false
			step := 1
			// fmt.Println("start Step Loop")
			for {
				i, j := x+step*p[0], y+step*p[1]
				if i < 0 || j < 0 || i >= n || j >= m {
					break
				}
				if g[i][j] == black {
					ok = true
					break
				}
				if g[i][j] == blank {
					break
				}
				if g[i][j] == white {
					step++
				}
			}
			// fmt.Println("End Step Loop", step)
			if !ok {
				continue
			}
			for i := 1; i < step; i++ {
				nx, ny := x+i*p[0], y+i*p[1]
				g[nx][ny] = black
			}
			for i := 1; i < step; i++ {
				nx, ny := x+i*p[0], y+i*p[1]
				res += dfs(nx, ny)
			}
			res += step - 1
		}

		return res
	}

	res := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if g[i][j] != blank {
				continue
			}
			// fmt.Println(">", i, j)
			g[i][j] = black
			cur := dfs(i, j)
			if cur != 0 {
				res = max(cur, res)
				gInit()
			} else {
				g[i][j] = blank
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
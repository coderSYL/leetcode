// Go
// leetcode 741
// https://leetcode.cn/problems/cherry-pickup/

func cherryPickup(g [][]int) int {
	n := len(g)
	f := [101][51][51]int{}
	for k := 0; k <= 2*n; k++ {
		for i := 0; i <= n; i++ {
			for j := 0; j <= n; j++ {
				f[k][i][j] = -10000
			}
		}
	}

	f[2][1][1] = g[0][0]

	for k := 3; k <= 2*n; k++ {
		for i1 := 1; i1 <= n; i1++ {
			for i2 := 1; i2 <= n; i2++ {
				j1, j2 := k-i1, k-i2
				if j1 <= 0 || j2 <= 0 || j1 > n || j2 > n {
					continue
				}
				A, B := g[i1-1][j1-1], g[i2-1][j2-1]
				if A == -1 || B == -1 {
					continue
				}

				a, b, c, d := f[k-1][i1-1][i2], f[k-1][i1-1][i2-1], f[k-1][i1][i2-1], f[k-1][i1][i2]
				t := maxOf4(a, b, c, d) + A
				if i1 != i2 {
					t += B
				}
				if t < 0 {
					continue
				}
				f[k][i1][i2] = t
			}
		}
	}
	if f[2*n][n][n] > 0 {
		return f[2*n][n][n]
	}
	return 0
}

func maxOf4(a, b, c, d int) int {
	if b > a {
		a = b
	}
	if c > a {
		a = c
	}
	if d > a {
		a = d
	}
	return a
}
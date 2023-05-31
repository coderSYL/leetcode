// Go
// leetcode 1263
// https://leetcode.cn/problems/minimum-moves-to-move-a-box-to-their-target-location/

func minPushBox(grid [][]byte) int {
	m, n := len(grid), len(grid[0])

	var iForS, jForS, iForB, jForB int

	for i, row := range grid {
		for j, c := range row {
			if c == 'S' {
				iForS, jForS = i, j
			} else if c == 'B' {
				iForB, jForB = i, j
			}
		}
	}

	var f func(i, j int) int
	f = func(i, j int) int {
		return i*n + j
	}

	var check func(i, j int) bool
	check = func(i, j int) bool {
		return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] != '#'
	}

	q := [][]int{[]int{f(iForS, jForS), f(iForB, jForB), 0}}
	vis := make([][]bool, m*n)
	for i := range vis {
		vis[i] = make([]bool, m*n)
	}
	vis[f(iForS, jForS)][f(iForB, jForB)] = true

	dirs := [5]int{-1, 0, 1, 0, -1}

	for len(q) > 0 {
		p := q[0]
		q = q[1:]
		iForS, jForS, iForB, jForB = p[0]/n, p[0]%n, p[1]/n, p[1]%n
		d := p[2]
		if grid[iForB][jForB] == 'T' {
			return d
		}
		for k := 0; k < 4; k++ {
			sx, sy := iForS+dirs[k], jForS+dirs[k+1]
			if !check(sx, sy) {
				continue
			}
			if sx == iForB && sy == jForB {
				bx, by := iForB+dirs[k], jForB+dirs[k+1]
				if !check(bx, by) || vis[f(sx, sy)][f(bx, by)] {
					continue
				}
				vis[f(sx, sy)][f(bx, by)] = true
				q = append(q, []int{f(sx, sy), f(bx, by), d + 1})
			} else if !vis[f(sx, sy)][f(iForB, jForB)] {
				vis[f(sx, sy)][f(iForB, jForB)] = true
				q = append([][]int{[]int{f(sx, sy), f(iForB, jForB), d}}, q...)
			}
		}
	}

	return -1
}
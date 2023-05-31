// Go
// leetcode 1091
// https://leetcode.cn/problems/shortest-path-in-binary-matrix/

func shortestPathBinaryMatrix(grid [][]int) int {
	n := len(grid)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			grid[i][j] *= -1
		}
	}
	if grid[0][0] == -1 || grid[n-1][n-1] == -1 {
		return -1
	}
	dirs := [][2]int{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}}
	outOfBound := func(x, y int) bool {
		return x < 0 || x >= n || y < 0 || y >= n
	}

	queue := []int{0}
	step := 1
	grid[0][0] = 1
	for len(queue) != 0 {
		step++
		sz := len(queue)
		for i := 0; i < sz; i++ {
			x, y := queue[i]/n, queue[i]%n
			for j := 0; j < 8; j++ {
				nx, ny := x+dirs[j][0], y+dirs[j][1]
				if outOfBound(nx, ny) {
					continue
				}
				if grid[nx][ny] != 0 {
					continue
				}
				grid[nx][ny] = step
				if nx == n-1 && ny == n-1 {
					return step
				}
				queue = append(queue, nx*n+ny)
			}
		}
		queue = queue[sz:]
	}

	if grid[n-1][n-1] == 0 {
		return -1
	}

	return grid[n-1][n-1]
}
// Go
// leetcode 980
// https://leetcode.cn/problems/unique-paths-iii/

func uniquePathsIII(grid [][]int) int {
	m, n := len(grid), len(grid[0])
	x, y := -1, -1
	goodPlace := 1 // 统计空格的数量（包括起点，不包括终点）
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			switch grid[i][j] {
			case 1:
				x, y = i, j
			case 2:
			case 0:
				goodPlace++
			}
		}
	}

	cnt := 0 // 统计走过的格子长度
	res := 0
	dirs := []int{-1, 0, 1, 0, -1}

	var dfs func(int, int)
	dfs = func(a, b int) {
		if grid[a][b] == 2 {
			if cnt == goodPlace {
				res++
			}
			return
		}
		grid[a][b] = -1
		cnt++
		for i := 0; i < 4; i++ {
			nx, ny := a+dirs[i], b+dirs[i+1]
			if nx < 0 || ny < 0 || nx >= m || ny >= n { // 越界
				continue
			}

			if grid[nx][ny] == -1 { // 有障碍，或者走过
				continue
			}
			dfs(nx, ny)
		}
		cnt--
		grid[a][b] = 0
	}
	dfs(x, y)
	return res
}
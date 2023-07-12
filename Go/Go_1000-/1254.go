// Go
// leetcode 1254
// https://leetcode.cn/problems/number-of-closed-islands/

func closedIsland(grid [][]int) int {
	idx := 2
	m, n := len(grid), len(grid[0])
    edgeLand := make(map[int]bool)
	dirs := []int{-1,0,1,0,-1}
	var dfs func(int, int, int)
	dfs = func(x, y, val int) {
		if grid[x][y] != 0 {
			return
		}

		if val > 1 {
			grid[x][y] = val
		} else {
			grid[x][y] = idx
			idx++
		}

		for i:=0; i<4; i++ {
			nx, ny := x+dirs[i], y+dirs[i+1]
			if nx <0 || ny < 0 || nx >= m || ny >= n {
                edgeLand[grid[x][y]] = true
                continue
			}
			dfs(nx,ny, grid[x][y])
		}
	}

    
	for i:=0; i<m; i++ {
		for j:=0; j<n; j++ {
			dfs(i, j, 0)
		}
	}
    // fmt.Println(grid)
	return idx-2-len(edgeLand)
}
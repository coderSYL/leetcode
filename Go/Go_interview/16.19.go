// Go
// leetcode interview 16.19
// https://leetcode.cn/problems/pond-sizes-lcci/

func pondSizes(land [][]int) []int {
	m, n := len(land), len(land[0])
	vis := make([][]bool, m)
	for i:=0; i<m; i++ {
		vis[i] = make([]bool, n)
	}

	dirs := [][2]int{{-1, -1}, {-1, 0}, {0, -1}, {1, -1},
		{-1, 1}, {1, 1}, {0, 1}, {1, 0}}
	
	var dfs func(int, int) int
	dfs = func(x, y int) int {
		if vis[x][y] {
			return 0
		}
		vis[x][y] = true
		if land[x][y] > 0 {
			return 0
		}

		res := 1
		for _, p := range dirs {
			nx, ny := x + p[0], y + p[1]
			if nx < 0 || ny<0 || nx >= m || ny >=n {
				continue
			}
			res += dfs(nx, ny)
		}

		return res
	}

	arr := []int{}
	for i:=0; i<m; i++ {
		for j:=0; j<n; j++ {
			cur := dfs(i, j)
			if cur > 0 {
				arr = append(arr, cur)
			}
		}
	}
	sort.Ints(arr)
	return arr
}
// Go
// leetcode 1042
// https://leetcode.cn/problems/flower-planting-with-no-adjacent/

func gardenNoAdj(n int, paths [][]int) []int {
	g := make([][]int, n)
	for i := 0; i < len(paths); i++ {
		x, y := paths[i][0]-1, paths[i][1]-1
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	color := make([]int, n)

	for i, gardens := range g {
		used := [5]bool{}
		for _, x := range gardens {
			used[color[x]] = true
		}
		for j := 1; j <= 4; j++ {
			if !used[j] {
				color[i] = j
				break
			}
		}
	}

	return color
}
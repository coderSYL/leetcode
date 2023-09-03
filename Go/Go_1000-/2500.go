// Go
// leetcode 2500
// https://leetcode.cn/problems/delete-greatest-value-in-each-row/

func deleteGreatestValue(grid [][]int) (res int) {
	m := len(grid)
	n := len(grid[0])
	for i:=0; i<m; i++ {
		sort.Ints(grid[i])
	}
	for i:= 0; i <n; i++ {
		cur := 0
		for j:=0; j<m; j++ {
			cur = max(cur, grid[j][i])
		}
		res += cur
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
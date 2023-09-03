// Go
// leetcode 1267
// https://leetcode.cn/problems/count-servers-that-communicate/

func countServers(grid [][]int) int {
	res := 0
	m, n := len(grid), len(grid[0])
	notAlone := make([][]bool, m)
	for i := range notAlone {
		notAlone[i] = make([]bool, n)
	}
	isGoodRow := make([]bool, m)
	for i:=0; i<m; i++ {
		cnt := 0
		for _, x := range grid[i] {
			cnt += x
		}
		if cnt > 1 {
			isGoodRow[i] = true
			res += cnt
			// fmt.Println("ROW", i, "GOOD", cnt)
		}
	}

	for i:=0; i<n; i++ {
		cnt := 0
		counted := 0
		for j:=0; j<m; j++ {
			x := grid[j][i]
			cnt += x
			if isGoodRow[j] {
				counted += x
			}
		}
		if cnt > 1 {
			// fmt.Println("COL", i, "good", cnt-counted)
			res += cnt - counted
		}
	}

	return res
}
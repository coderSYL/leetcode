// Go
// leetcode 1289
// https://leetcode.cn/problems/minimum-falling-path-sum-ii/

func minFallingPathSum(grid [][]int) int {
	n := len(grid)
	arr := make([]int, n)
	for i:=0; i<n; i++ {
		arr[i] = grid[0][i]
	}
	mn1, mn2 := 100, 100
	update := func(x int) {
		mn2 = min(mn2, x)
		if mn1 > mn2 {
			mn1, mn2 = mn2, mn1
		}
	}
	tmp := make([]int, n)
	for row := 1; row < n; row++ {
		mn1, mn2 = 30000, 30000
		for _, x := range arr {
			update(x)
		}
		for i:=0; i<n; i++ {
			if arr[i] == mn1 {
				tmp[i] = mn2 + grid[row][i]
			} else {
				tmp[i] = mn1 + grid[row][i]
			}
		}

		for i:=0; i<n; i++ {
			arr[i] = tmp[i]
		}
	}

	res := 30000
	for _, x := range arr {
		res = min(res, x)
	}

	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
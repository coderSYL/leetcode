// Go
// leetcode 85
// https://leetcode.cn/problems/maximal-rectangle/

func maximalRectangle(matrix [][]byte) (res int) {
	m, n := len(matrix), len(matrix[0])

	// info[i][j]表示此位置左侧距离最近的 0 的位置
	info := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		info[i] = make([]int, n)
	}

	for i := 0; i < m; i++ {
		// 第一个
		if matrix[i][0] == '1' {
			info[i][0] = 1
		}

		// 后面的都是
		for j := 1; j < n; j++ {
			if matrix[i][j] == '1' {
				info[i][j] = info[i][j-1] + 1
			} else {
				info[i][j] = 0
			}
		}
	}

	for j := 0; j < n; j++ {
		stk := []int{}
		for i := 0; i <= m; i++ {
			for len(stk) != 0 && info[stk[len(stk)-1]][j] > info[i][j] {
				tmp := stk[len(stk)-1]
				stk = stk[:len(stk)-1]
				x := i
				if len(stk) != 0 {
					x -= stk[len(stk)-1] + 1
				}
				res = max(res, info[tmp][j]*x)
			}
			stk = append(stk, i)
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
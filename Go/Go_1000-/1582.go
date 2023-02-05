// Go
// leetcode 1582
// https://leetcode.cn/problems/special-positions-in-a-binary-matrix/

func numSpecial(mat [][]int) (res int) {
	m, n := len(mat), len(mat[0])

	// 统计每行每列 1 的个数
	cnt_m, cnt_n := make([]int, m), make([]int, n)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if mat[i][j] == 1 {
				cnt_m[i]++
				cnt_n[j]++
			}
		}
	}

	for i := 0; i < m; i++ {
		// 此行 1 的个数不合格，过
		if cnt_m[i] != 1 {
			continue
		}

		// 检查列
		for j := 0; j < n; j++ {
			if cnt_n[j] == 1 && mat[i][j] == 1 {
				res++
			}
		}
	}
	return res
}
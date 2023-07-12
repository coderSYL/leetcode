// Go
// leetcode 931
// https://leetcode.cn/problems/minimum-falling-path-sum/

func minFallingPathSum(matrix [][]int) int {
    m, n := len(matrix), len(matrix[0])
    for i:= m-2; i >= 0; i-- {
        for j := 0; j<n; j++ {
            cur := matrix[i+1][j]
			if j >0 {
				cur = min(cur, matrix[i+1][j-1])
			}

			if j <n-1 {
				cur = min(cur, matrix[i+1][j+1])
			}
			matrix[i][j] += cur
        }
    }
	res := 100_000_000
	for _, x := range matrix[0] {
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
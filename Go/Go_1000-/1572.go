// Go
// leetcode 1572
// https://leetcode.cn/problems/matrix-diagonal-sum/

func diagonalSum(mat [][]int) int {
	n := len(mat)
	sum := 0
	for i:=0; i<n; i++ {
		sum += mat[i][i]
		if n-i-1 != i {
			sum += mat[i][n-i-1]
		}
	}
	return sum
}
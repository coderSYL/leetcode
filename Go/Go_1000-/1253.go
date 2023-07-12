// Go
// leetcode 1253
// https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/

func reconstructMatrix(upper int, lower int, colsum []int) [][]int {
	n := len(colsum)
	res := make([][]int, 2)
	res[0] = make([]int, n)
	res[1] = make([]int, n)

	for i:=0; i<n; i++ {
		switch colsum[i] {
		case 0:
		case 1:
			if upper > lower {
				res[0][i] = 1
				upper--
			} else {
				res[1][i] = 1
				lower--
			}
		case 2:
			res[0][i] = 1
			res[1][i] = 1
			lower--
			upper--
		}
	}

    if lower != 0 || upper != 0 { // 数字没用完，
        return [][]int{}
    }

	return res
}
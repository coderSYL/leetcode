// Go
// leetcode 2596
// https://leetcode.cn/problems/check-knight-tour-configuration/

func checkValidGrid(grid [][]int) bool {
	n := len(grid)
	location := make([]int, n*n)

	for i, arr := range grid {
		for j, x := range arr {
			location[x] = i*n + j
		}
	}

	if location[0] != 0 {
		return false
	}

	avaliable := func(n1, n2 int) bool { // 两个位置间的移动是否有效
		x, y := n1/n, n1%n
		a, b := n2/n, n2%n
		return abs(x-a) * abs(y-b) == 2
	}

	for i:=1; i<n*n; i++ {
		if !avaliable(location[i-1],location[i]) {
			return false
		}
	}

	return true
}

func abs(a int) int { // 绝对值
	if a < 0 {
		return -a
	}
	return a
}